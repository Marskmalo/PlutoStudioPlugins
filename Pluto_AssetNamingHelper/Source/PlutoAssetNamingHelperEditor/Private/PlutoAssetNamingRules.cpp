#include "PlutoAssetNamingRules.h"

#include "Internationalization/Regex.h"

#define LOCTEXT_NAMESPACE "PlutoAssetNamingRules"

namespace
{
	bool IsAsciiAssetPath(const FString& Value)
	{
		for (const TCHAR Character : Value)
		{
			if (Character > 127)
			{
				return false;
			}
		}
		return true;
	}

	bool IsValidAssetName(const FString& Name)
	{
		if (Name.IsEmpty())
		{
			return false;
		}

		for (const TCHAR Character : Name)
		{
			if (!(FChar::IsAlnum(Character) || Character == TEXT('_')) || Character > 127)
			{
				return false;
			}
		}
		return !Name.Contains(TEXT("__"));
	}

	FString RecognizeRegisteredPrefix(const FString& AssetName)
	{
		static const TCHAR* Prefixes[] =
		{
			TEXT("BPML"), TEXT("BPI"), TEXT("BPL"), TEXT("BPA"), TEXT("BPS"),
			TEXT("SKEL"), TEXT("PHYS"), TEXT("EQSC"), TEXT("BTS"), TEXT("BTD"),
			TEXT("BTT"), TEXT("IMC"), TEXT("PDA"), TEXT("MPC"), TEXT("ABP"),
			TEXT("WBP"), TEXT("EQS"), TEXT("MI"), TEXT("MF"), TEXT("PM"),
			TEXT("SM"), TEXT("SK"), TEXT("DT"), TEXT("DA"), TEXT("IA"),
			TEXT("BT"), TEXT("BB"), TEXT("CR"), TEXT("NS"), TEXT("NE"),
			TEXT("SL"), TEXT("BP"), TEXT("AM"), TEXT("BS"), TEXT("M"),
			TEXT("T"), TEXT("A"), TEXT("E"), TEXT("S"), TEXT("L")
		};

		for (const TCHAR* Prefix : Prefixes)
		{
			const FString Token = FString(Prefix) + TEXT("_");
			if (AssetName.StartsWith(Token, ESearchCase::CaseSensitive))
			{
				return Prefix;
			}
		}
		return FString();
	}

	FString GetExpectedPrefix(const FAssetData& AssetData)
	{
		const FString AssetName = AssetData.AssetName.ToString();
		const FString ClassName = AssetData.AssetClassPath.GetAssetName().ToString();

		if (ClassName == TEXT("ObjectRedirector")) return TEXT("Redirector");
		if (ClassName == TEXT("InputAction")) return TEXT("IA");
		if (ClassName == TEXT("InputMappingContext")) return TEXT("IMC");
		if (ClassName == TEXT("BehaviorTree")) return TEXT("BT");
		if (ClassName == TEXT("BlackboardData")) return TEXT("BB");
		if (ClassName == TEXT("EnvQuery")) return TEXT("EQS");
		if (ClassName.Contains(TEXT("EnvQueryContext"))) return TEXT("EQSC");
		if (ClassName == TEXT("Material")) return TEXT("M");
		if (ClassName.StartsWith(TEXT("MaterialInstance"))) return TEXT("MI");
		if (ClassName.StartsWith(TEXT("MaterialFunction"))) return TEXT("MF");
		if (ClassName == TEXT("MaterialParameterCollection")) return TEXT("MPC");
		if (ClassName == TEXT("PhysicalMaterial")) return TEXT("PM");
		if (ClassName.StartsWith(TEXT("Texture"))) return TEXT("T");
		if (ClassName == TEXT("StaticMesh")) return TEXT("SM");
		if (ClassName == TEXT("SkeletalMesh")) return TEXT("SK");
		if (ClassName == TEXT("Skeleton")) return TEXT("SKEL");
		if (ClassName == TEXT("PhysicsAsset")) return TEXT("PHYS");
		if (ClassName == TEXT("AnimBlueprint")) return TEXT("ABP");
		if (ClassName == TEXT("AnimSequence")) return TEXT("A");
		if (ClassName == TEXT("AnimMontage")) return TEXT("AM");
		if (ClassName.Contains(TEXT("BlendSpace"))) return TEXT("BS");
		if (ClassName.Contains(TEXT("ControlRig"))) return TEXT("CR");
		if (ClassName == TEXT("WidgetBlueprint")) return TEXT("WBP");
		if (ClassName == TEXT("NiagaraSystem")) return TEXT("NS");
		if (ClassName == TEXT("NiagaraEmitter")) return TEXT("NE");
		if (ClassName == TEXT("DataTable")) return TEXT("DT");
		if (ClassName == TEXT("UserDefinedEnum")) return TEXT("E");
		if (ClassName == TEXT("UserDefinedStruct")) return TEXT("S");
		if (ClassName == TEXT("World")) return AssetName.StartsWith(TEXT("SL_")) ? TEXT("SL") : TEXT("L");

		const FString RegisteredPrefix = RecognizeRegisteredPrefix(AssetName);
		if (!RegisteredPrefix.IsEmpty())
		{
			return RegisteredPrefix;
		}

		if (ClassName == TEXT("Blueprint")) return TEXT("BP");
		return FString();
	}

	FString MakeSuggestedName(const FString& AssetName, const FString& ExpectedPrefix)
	{
		const FString ExpectedToken = ExpectedPrefix + TEXT("_");
		const FString RecognizedPrefix = RecognizeRegisteredPrefix(AssetName);

		if (AssetName.StartsWith(TEXT("SOD_") + ExpectedToken))
		{
			return ExpectedToken + TEXT("SOD_") + AssetName.RightChop(4 + ExpectedToken.Len());
		}

		if (!RecognizedPrefix.IsEmpty())
		{
			return ExpectedToken + TEXT("SOD_") + AssetName.RightChop(RecognizedPrefix.Len() + 1);
		}

		return ExpectedToken + TEXT("SOD_") + AssetName;
	}

	bool IsHighRiskClass(const FString& ClassName)
	{
		return ClassName == TEXT("World")
			|| ClassName == TEXT("ObjectRedirector")
			|| ClassName == TEXT("Blueprint")
			|| ClassName == TEXT("AnimBlueprint")
			|| ClassName == TEXT("WidgetBlueprint");
	}
}

FPlutoAssetNamingAuditResult PlutoAssetNamingRules::Audit(const FAssetData& AssetData)
{
	FPlutoAssetNamingAuditResult Result;
	Result.AssetData = AssetData;
	Result.AssetTypeLabel = AssetData.AssetClassPath.GetAssetName().ToString();
	Result.OwnerLabel = AssetData.PackagePath.ToString().StartsWith(TEXT("/Game/SOD")) ? TEXT("SOD") : TEXT("待确认");
	Result.ExpectedPrefix = GetExpectedPrefix(AssetData);

	const FString AssetName = AssetData.AssetName.ToString();
	const FString PackageName = AssetData.PackageName.ToString();
	const FString ClassName = AssetData.AssetClassPath.GetAssetName().ToString();

	if (ClassName == TEXT("ObjectRedirector"))
	{
		Result.Status = EPlutoAssetNamingStatus::Protected;
		Result.Issue = TEXT("这是重定向器，必须先检查引用再处理");
		Result.TechnicalDetails = TEXT("Object Redirector 禁止自动改名或删除，需要独立执行 Fix Up Redirectors 并验证引用。");
		return Result;
	}

	if (!IsAsciiAssetPath(PackageName) || !IsValidAssetName(AssetName))
	{
		Result.Status = EPlutoAssetNamingStatus::SuggestedMigration;
		Result.Issue = TEXT("名称或路径含有中文、空格或其他不兼容字符");
		Result.TechnicalDetails = TEXT("资产路径和名称只允许 ASCII 字母、数字与单个下划线。");
		Result.bRenameAllowed = false;
		return Result;
	}

	if (AssetName == TEXT("M_SOD_OutLine") || AssetName == TEXT("MI_SOD_OutLine"))
	{
		Result.Status = EPlutoAssetNamingStatus::HistoricalException;
		Result.Issue = TEXT("旧资产使用了“OutLine”拼写，可以继续保留");
		Result.TechnicalDetails = TEXT("新资产统一使用 PascalCase 拼写 Outline；父材质和实例应当一起规划迁移。");
		Result.SuggestedName = AssetName.Replace(TEXT("OutLine"), TEXT("Outline"));
		return Result;
	}

	if (AssetName == TEXT("BP_Mirror") || AssetName == TEXT("BP_InterestTest") || AssetName == TEXT("BP_JumpThroughProxy"))
	{
		Result.Status = EPlutoAssetNamingStatus::HistoricalException;
		Result.Issue = TEXT("暂不确定是否为 SOD 自研资产");
		Result.TechnicalDetails = TEXT("需要先确认来源、维护责任和引用范围，不能只根据所在文件夹判断所有权。");
		return Result;
	}

	if (AssetName == TEXT("IA_Move") || AssetName == TEXT("IA_Look") || AssetName == TEXT("IA_Drag"))
	{
		Result.Status = EPlutoAssetNamingStatus::SuggestedMigration;
		Result.Issue = TEXT("名称里缺少项目标识“SOD”");
		Result.TechnicalDetails = TEXT("SOD 自研 Input Action 使用 IA_SOD_<Name> 格式。");
		Result.SuggestedName = TEXT("IA_SOD_") + AssetName.RightChop(3);
		Result.bRenameAllowed = true;
		return Result;
	}

	if (AssetName == TEXT("SOD_L_Playground"))
	{
		Result.Status = EPlutoAssetNamingStatus::SuggestedMigration;
		Result.Issue = TEXT("“L”应放在名称最前面");
		Result.TechnicalDetails = TEXT("统一语法要求类型前缀位于最前，关卡使用 L_SOD_<Name>。");
		Result.SuggestedName = TEXT("L_SOD_Playground");
		Result.bRenameAllowed = false;
		return Result;
	}

	if (Result.ExpectedPrefix.IsEmpty())
	{
		Result.Status = EPlutoAssetNamingStatus::HistoricalException;
		Result.Issue = TEXT("这种资产类型还没有登记命名规则");
		Result.TechnicalDetails = FString::Printf(TEXT("未登记资产类：%s。请先补充规范，不要临时猜测前缀。"), *ClassName);
		return Result;
	}

	const FString ExpectedStart = Result.ExpectedPrefix + TEXT("_SOD_");
	if (AssetName.StartsWith(ExpectedStart, ESearchCase::CaseSensitive))
	{
		static const TCHAR* DiscouragedVariants[] = { TEXT("_New"), TEXT("_Final"), TEXT("_Final2"), TEXT("_TestLatest") };
		for (const TCHAR* Variant : DiscouragedVariants)
		{
			if (AssetName.Contains(Variant, ESearchCase::IgnoreCase))
			{
				Result.Status = EPlutoAssetNamingStatus::SuggestedMigration;
				Result.Issue = TEXT("名称里使用了无法长期维护的版本词");
				Result.TechnicalDetails = TEXT("不要使用 New、Final、Final2 或 TestLatest；应使用明确的用途或编号。");
				return Result;
			}
		}

		if (Result.ExpectedPrefix == TEXT("T"))
		{
			static const TCHAR* TextureSuffixes[] = { TEXT("_BC"), TEXT("_N"), TEXT("_R"), TEXT("_M"), TEXT("_AO"), TEXT("_E"), TEXT("_A"), TEXT("_ORM") };
			bool bHasTextureSuffix = false;
			for (const TCHAR* Suffix : TextureSuffixes)
			{
				bHasTextureSuffix |= AssetName.EndsWith(Suffix);
			}
			if (!bHasTextureSuffix)
			{
				Result.Status = EPlutoAssetNamingStatus::HistoricalException;
				Result.Issue = TEXT("纹理用途还需要人工确认");
				Result.TechnicalDetails = TEXT("纹理应按用途添加 BC、N、R、M、AO、E、A 或 ORM 后缀。");
				return Result;
			}
		}

		Result.Status = EPlutoAssetNamingStatus::Compliant;
		Result.Issue = TEXT("名称正确，无需修改");
		Result.TechnicalDetails = FString::Printf(TEXT("符合 %s_SOD_<BaseAssetName> 命名格式。"), *Result.ExpectedPrefix);
		return Result;
	}

	const FString RecognizedPrefix = RecognizeRegisteredPrefix(AssetName);
	if (AssetName.StartsWith(TEXT("SOD_") + Result.ExpectedPrefix + TEXT("_"))
		|| (!RecognizedPrefix.IsEmpty() && AssetName.Contains(TEXT("_SOD_"))))
	{
		Result.Status = EPlutoAssetNamingStatus::SuggestedMigration;
		Result.Issue = TEXT("资产类型标识的位置或类型不正确");
		Result.TechnicalDetails = FString::Printf(TEXT("该资产应以 %s_SOD_ 开头。"), *Result.ExpectedPrefix);
		Result.SuggestedName = MakeSuggestedName(AssetName, Result.ExpectedPrefix);
		Result.bRenameAllowed = !IsHighRiskClass(ClassName);
		return Result;
	}

	Result.Status = EPlutoAssetNamingStatus::HistoricalException;
	Result.Issue = TEXT("暂不确定是否应改成 SOD 命名");
	Result.TechnicalDetails = FString::Printf(
		TEXT("当前资产缺少 SOD 所有权标识。先确认来源与维护责任；确认由 SOD 接管后，建议使用 %s。"),
		*MakeSuggestedName(AssetName, Result.ExpectedPrefix));
	Result.SuggestedName = MakeSuggestedName(AssetName, Result.ExpectedPrefix);
	return Result;
}

FText PlutoAssetNamingRules::GetStatusText(EPlutoAssetNamingStatus Status)
{
	switch (Status)
	{
	case EPlutoAssetNamingStatus::Compliant: return LOCTEXT("Compliant", "符合");
	case EPlutoAssetNamingStatus::HistoricalException: return LOCTEXT("HistoricalException", "历史例外");
	case EPlutoAssetNamingStatus::SuggestedMigration: return LOCTEXT("SuggestedMigration", "建议迁移");
	case EPlutoAssetNamingStatus::Protected: return LOCTEXT("Protected", "禁止自动修改");
	default: return FText::GetEmpty();
	}
}

FLinearColor PlutoAssetNamingRules::GetStatusColor(EPlutoAssetNamingStatus Status)
{
	switch (Status)
	{
	case EPlutoAssetNamingStatus::Compliant: return FLinearColor(0.22f, 0.72f, 0.24f, 1.0f);
	case EPlutoAssetNamingStatus::HistoricalException: return FLinearColor(0.95f, 0.68f, 0.12f, 1.0f);
	case EPlutoAssetNamingStatus::SuggestedMigration: return FLinearColor(1.0f, 0.42f, 0.08f, 1.0f);
	case EPlutoAssetNamingStatus::Protected: return FLinearColor(0.95f, 0.20f, 0.20f, 1.0f);
	default: return FLinearColor::White;
	}
}

#undef LOCTEXT_NAMESPACE
