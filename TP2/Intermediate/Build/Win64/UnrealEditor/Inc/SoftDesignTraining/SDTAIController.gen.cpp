// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTAIController() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTAIController_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTAIController();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTBaseAIController();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
// End Cross Module References
	void ASDTAIController::StaticRegisterNativesASDTAIController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASDTAIController);
	UClass* Z_Construct_UClass_ASDTAIController_NoRegister()
	{
		return ASDTAIController::StaticClass();
	}
	struct Z_Construct_UClass_ASDTAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_DetectionCapsuleHalfLength_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_m_DetectionCapsuleHalfLength;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_DetectionCapsuleRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_m_DetectionCapsuleRadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_DetectionCapsuleForwardStartingOffset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_m_DetectionCapsuleForwardStartingOffset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpCurve_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpApexHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_JumpApexHeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_JumpSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AtJumpSegment_MetaData[];
#endif
		static void NewProp_AtJumpSegment_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_AtJumpSegment;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InAir_MetaData[];
#endif
		static void NewProp_InAir_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_InAir;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Landing_MetaData[];
#endif
		static void NewProp_Landing_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Landing;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASDTAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ASDTBaseAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::Class_MetaDataParams[] = {
		{ "ClassGroupNames", "AI" },
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "SDTAIController.h" },
		{ "ModuleRelativePath", "SDTAIController.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleHalfLength_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleHalfLength = { "m_DetectionCapsuleHalfLength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, m_DetectionCapsuleHalfLength), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleHalfLength_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleHalfLength_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleRadius_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleRadius = { "m_DetectionCapsuleRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, m_DetectionCapsuleRadius), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleRadius_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleForwardStartingOffset_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleForwardStartingOffset = { "m_DetectionCapsuleForwardStartingOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, m_DetectionCapsuleForwardStartingOffset), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleForwardStartingOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleForwardStartingOffset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpCurve_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpCurve = { "JumpCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, JumpCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpCurve_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpApexHeight_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpApexHeight = { "JumpApexHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, JumpApexHeight), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpApexHeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpApexHeight_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpSpeed_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpSpeed = { "JumpSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, JumpSpeed), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	void Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment_SetBit(void* Obj)
	{
		((ASDTAIController*)Obj)->AtJumpSegment = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment = { "AtJumpSegment", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASDTAIController), &Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	void Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir_SetBit(void* Obj)
	{
		((ASDTAIController*)Obj)->InAir = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir = { "InAir", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASDTAIController), &Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	void Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing_SetBit(void* Obj)
	{
		((ASDTAIController*)Obj)->Landing = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing = { "Landing", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASDTAIController), &Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASDTAIController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleHalfLength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleForwardStartingOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpApexHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASDTAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASDTAIController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASDTAIController_Statics::ClassParams = {
		&ASDTAIController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASDTAIController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASDTAIController()
	{
		if (!Z_Registration_Info_UClass_ASDTAIController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASDTAIController.OuterSingleton, Z_Construct_UClass_ASDTAIController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASDTAIController.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASDTAIController>()
	{
		return ASDTAIController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASDTAIController);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAIController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAIController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASDTAIController, ASDTAIController::StaticClass, TEXT("ASDTAIController"), &Z_Registration_Info_UClass_ASDTAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASDTAIController), 4198204414U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAIController_h_3933173392(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTAIController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
