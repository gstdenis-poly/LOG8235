// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SoftDesignTrainingPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoftDesignTrainingPlayerController() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingPlayerController_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void ASoftDesignTrainingPlayerController::StaticRegisterNativesASoftDesignTrainingPlayerController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASoftDesignTrainingPlayerController);
	UClass* Z_Construct_UClass_ASoftDesignTrainingPlayerController_NoRegister()
	{
		return ASoftDesignTrainingPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ASoftDesignTrainingPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASoftDesignTrainingPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "SoftDesignTrainingPlayerController.h" },
		{ "ModuleRelativePath", "SoftDesignTrainingPlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASoftDesignTrainingPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASoftDesignTrainingPlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASoftDesignTrainingPlayerController_Statics::ClassParams = {
		&ASoftDesignTrainingPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASoftDesignTrainingPlayerController()
	{
		if (!Z_Registration_Info_UClass_ASoftDesignTrainingPlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASoftDesignTrainingPlayerController.OuterSingleton, Z_Construct_UClass_ASoftDesignTrainingPlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASoftDesignTrainingPlayerController.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASoftDesignTrainingPlayerController>()
	{
		return ASoftDesignTrainingPlayerController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASoftDesignTrainingPlayerController);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingPlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingPlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASoftDesignTrainingPlayerController, ASoftDesignTrainingPlayerController::StaticClass, TEXT("ASoftDesignTrainingPlayerController"), &Z_Registration_Info_UClass_ASoftDesignTrainingPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASoftDesignTrainingPlayerController), 3596958595U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingPlayerController_h_1246904544(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingPlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
