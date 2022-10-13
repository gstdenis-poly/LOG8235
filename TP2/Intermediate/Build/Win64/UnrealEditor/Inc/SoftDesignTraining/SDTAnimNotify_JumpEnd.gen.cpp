// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTAnimNotify_JumpEnd.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTAnimNotify_JumpEnd() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_USDTAnimNotify_JumpEnd_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_USDTAnimNotify_JumpEnd();
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void USDTAnimNotify_JumpEnd::StaticRegisterNativesUSDTAnimNotify_JumpEnd()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USDTAnimNotify_JumpEnd);
	UClass* Z_Construct_UClass_USDTAnimNotify_JumpEnd_NoRegister()
	{
		return USDTAnimNotify_JumpEnd::StaticClass();
	}
	struct Z_Construct_UClass_USDTAnimNotify_JumpEnd_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USDTAnimNotify_JumpEnd_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USDTAnimNotify_JumpEnd_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "SDTAnimNotify_JumpEnd.h" },
		{ "ModuleRelativePath", "SDTAnimNotify_JumpEnd.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USDTAnimNotify_JumpEnd_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USDTAnimNotify_JumpEnd>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USDTAnimNotify_JumpEnd_Statics::ClassParams = {
		&USDTAnimNotify_JumpEnd::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_USDTAnimNotify_JumpEnd_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USDTAnimNotify_JumpEnd_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USDTAnimNotify_JumpEnd()
	{
		if (!Z_Registration_Info_UClass_USDTAnimNotify_JumpEnd.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USDTAnimNotify_JumpEnd.OuterSingleton, Z_Construct_UClass_USDTAnimNotify_JumpEnd_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USDTAnimNotify_JumpEnd.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<USDTAnimNotify_JumpEnd>()
	{
		return USDTAnimNotify_JumpEnd::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USDTAnimNotify_JumpEnd);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAnimNotify_JumpEnd_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAnimNotify_JumpEnd_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USDTAnimNotify_JumpEnd, USDTAnimNotify_JumpEnd::StaticClass, TEXT("USDTAnimNotify_JumpEnd"), &Z_Registration_Info_UClass_USDTAnimNotify_JumpEnd, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USDTAnimNotify_JumpEnd), 317165879U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAnimNotify_JumpEnd_h_3608672239(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAnimNotify_JumpEnd_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAnimNotify_JumpEnd_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
