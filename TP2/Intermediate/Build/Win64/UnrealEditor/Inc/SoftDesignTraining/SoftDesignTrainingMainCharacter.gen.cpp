// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SoftDesignTrainingMainCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoftDesignTrainingMainCharacter() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingMainCharacter_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingMainCharacter();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingCharacter();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
	void ASoftDesignTrainingMainCharacter::StaticRegisterNativesASoftDesignTrainingMainCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASoftDesignTrainingMainCharacter);
	UClass* Z_Construct_UClass_ASoftDesignTrainingMainCharacter_NoRegister()
	{
		return ASoftDesignTrainingMainCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_TopDownCameraComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_TopDownCameraComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_PowerUpDuration_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_m_PowerUpDuration;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_PoweredUpMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_PoweredUpMaterial;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ASoftDesignTrainingCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "SoftDesignTrainingMainCharacter.h" },
		{ "ModuleRelativePath", "SoftDesignTrainingMainCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_TopDownCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SoftDesignTrainingMainCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_TopDownCameraComponent = { "m_TopDownCameraComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftDesignTrainingMainCharacter, m_TopDownCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_TopDownCameraComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_TopDownCameraComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SoftDesignTrainingMainCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_CameraBoom = { "m_CameraBoom", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftDesignTrainingMainCharacter, m_CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PowerUpDuration_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SoftDesignTrainingMainCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PowerUpDuration = { "m_PowerUpDuration", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftDesignTrainingMainCharacter, m_PowerUpDuration), METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PowerUpDuration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PowerUpDuration_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PoweredUpMaterial_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SoftDesignTrainingMainCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PoweredUpMaterial = { "m_PoweredUpMaterial", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftDesignTrainingMainCharacter, m_PoweredUpMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PoweredUpMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PoweredUpMaterial_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_TopDownCameraComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PowerUpDuration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PoweredUpMaterial,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASoftDesignTrainingMainCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::ClassParams = {
		&ASoftDesignTrainingMainCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASoftDesignTrainingMainCharacter()
	{
		if (!Z_Registration_Info_UClass_ASoftDesignTrainingMainCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASoftDesignTrainingMainCharacter.OuterSingleton, Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASoftDesignTrainingMainCharacter.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASoftDesignTrainingMainCharacter>()
	{
		return ASoftDesignTrainingMainCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASoftDesignTrainingMainCharacter);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingMainCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingMainCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASoftDesignTrainingMainCharacter, ASoftDesignTrainingMainCharacter::StaticClass, TEXT("ASoftDesignTrainingMainCharacter"), &Z_Registration_Info_UClass_ASoftDesignTrainingMainCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASoftDesignTrainingMainCharacter), 3175522150U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingMainCharacter_h_369186145(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingMainCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SoftDesignTrainingMainCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
