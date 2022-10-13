// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTNavArea_Jump.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTNavArea_Jump() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_USDTNavArea_Jump_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_USDTNavArea_Jump();
	NAVIGATIONSYSTEM_API UClass* Z_Construct_UClass_UNavArea();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void USDTNavArea_Jump::StaticRegisterNativesUSDTNavArea_Jump()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USDTNavArea_Jump);
	UClass* Z_Construct_UClass_USDTNavArea_Jump_NoRegister()
	{
		return USDTNavArea_Jump::StaticClass();
	}
	struct Z_Construct_UClass_USDTNavArea_Jump_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USDTNavArea_Jump_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UNavArea,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USDTNavArea_Jump_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "SDTNavArea_Jump.h" },
		{ "ModuleRelativePath", "SDTNavArea_Jump.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USDTNavArea_Jump_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USDTNavArea_Jump>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USDTNavArea_Jump_Statics::ClassParams = {
		&USDTNavArea_Jump::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x003000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USDTNavArea_Jump_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USDTNavArea_Jump_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USDTNavArea_Jump()
	{
		if (!Z_Registration_Info_UClass_USDTNavArea_Jump.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USDTNavArea_Jump.OuterSingleton, Z_Construct_UClass_USDTNavArea_Jump_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USDTNavArea_Jump.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<USDTNavArea_Jump>()
	{
		return USDTNavArea_Jump::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USDTNavArea_Jump);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTNavArea_Jump_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTNavArea_Jump_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USDTNavArea_Jump, USDTNavArea_Jump::StaticClass, TEXT("USDTNavArea_Jump"), &Z_Registration_Info_UClass_USDTNavArea_Jump, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USDTNavArea_Jump), 3530947326U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTNavArea_Jump_h_2444112154(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTNavArea_Jump_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTNavArea_Jump_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
