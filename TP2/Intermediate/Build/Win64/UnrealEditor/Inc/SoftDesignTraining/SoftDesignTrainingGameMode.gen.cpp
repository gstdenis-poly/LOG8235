// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SoftDesignTrainingGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoftDesignTrainingGameMode() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingGameMode_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void ASoftDesignTrainingGameMode::StaticRegisterNativesASoftDesignTrainingGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASoftDesignTrainingGameMode);
	UClass* Z_Construct_UClass_ASoftDesignTrainingGameMode_NoRegister()
	{
		return ASoftDesignTrainingGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SoftDesignTrainingGameMode.h" },
		{ "ModuleRelativePath", "SoftDesignTrainingGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASoftDesignTrainingGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::ClassParams = {
		&ASoftDesignTrainingGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASoftDesignTrainingGameMode()
	{
		if (!Z_Registration_Info_UClass_ASoftDesignTrainingGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASoftDesignTrainingGameMode.OuterSingleton, Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASoftDesignTrainingGameMode.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASoftDesignTrainingGameMode>()
	{
		return ASoftDesignTrainingGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASoftDesignTrainingGameMode);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASoftDesignTrainingGameMode, ASoftDesignTrainingGameMode::StaticClass, TEXT("ASoftDesignTrainingGameMode"), &Z_Registration_Info_UClass_ASoftDesignTrainingGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASoftDesignTrainingGameMode), 1896664815U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingGameMode_h_3113259314(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
