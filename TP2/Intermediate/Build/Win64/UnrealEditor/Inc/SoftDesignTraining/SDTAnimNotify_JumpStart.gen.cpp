// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTAnimNotify_JumpStart.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTAnimNotify_JumpStart() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_USDTAnimNotify_JumpStart_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_USDTAnimNotify_JumpStart();
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void USDTAnimNotify_JumpStart::StaticRegisterNativesUSDTAnimNotify_JumpStart()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USDTAnimNotify_JumpStart);
	UClass* Z_Construct_UClass_USDTAnimNotify_JumpStart_NoRegister()
	{
		return USDTAnimNotify_JumpStart::StaticClass();
	}
	struct Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "SDTAnimNotify_JumpStart.h" },
		{ "ModuleRelativePath", "SDTAnimNotify_JumpStart.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USDTAnimNotify_JumpStart>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::ClassParams = {
		&USDTAnimNotify_JumpStart::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001120A0u,
		METADATA_PARAMS(Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USDTAnimNotify_JumpStart()
	{
		if (!Z_Registration_Info_UClass_USDTAnimNotify_JumpStart.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USDTAnimNotify_JumpStart.OuterSingleton, Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USDTAnimNotify_JumpStart.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<USDTAnimNotify_JumpStart>()
	{
		return USDTAnimNotify_JumpStart::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USDTAnimNotify_JumpStart);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAnimNotify_JumpStart_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAnimNotify_JumpStart_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USDTAnimNotify_JumpStart, USDTAnimNotify_JumpStart::StaticClass, TEXT("USDTAnimNotify_JumpStart"), &Z_Registration_Info_UClass_USDTAnimNotify_JumpStart, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USDTAnimNotify_JumpStart), 321059669U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAnimNotify_JumpStart_h_3949086990(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAnimNotify_JumpStart_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAnimNotify_JumpStart_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
