// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTBaseAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTBaseAIController() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTBaseAIController_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTBaseAIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void ASDTBaseAIController::StaticRegisterNativesASDTBaseAIController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASDTBaseAIController);
	UClass* Z_Construct_UClass_ASDTBaseAIController_NoRegister()
	{
		return ASDTBaseAIController::StaticClass();
	}
	struct Z_Construct_UClass_ASDTBaseAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASDTBaseAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTBaseAIController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "SDTBaseAIController.h" },
		{ "ModuleRelativePath", "SDTBaseAIController.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASDTBaseAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASDTBaseAIController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASDTBaseAIController_Statics::ClassParams = {
		&ASDTBaseAIController::StaticClass,
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
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASDTBaseAIController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTBaseAIController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASDTBaseAIController()
	{
		if (!Z_Registration_Info_UClass_ASDTBaseAIController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASDTBaseAIController.OuterSingleton, Z_Construct_UClass_ASDTBaseAIController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASDTBaseAIController.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASDTBaseAIController>()
	{
		return ASDTBaseAIController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASDTBaseAIController);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTBaseAIController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTBaseAIController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASDTBaseAIController, ASDTBaseAIController::StaticClass, TEXT("ASDTBaseAIController"), &Z_Registration_Info_UClass_ASDTBaseAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASDTBaseAIController), 1283909341U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTBaseAIController_h_4148740887(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTBaseAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTBaseAIController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
