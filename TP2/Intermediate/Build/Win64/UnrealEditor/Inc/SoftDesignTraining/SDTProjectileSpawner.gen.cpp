// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTProjectileSpawner.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTProjectileSpawner() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTProjectileSpawner_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTProjectileSpawner();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTProjectile_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	void ASDTProjectileSpawner::StaticRegisterNativesASDTProjectileSpawner()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASDTProjectileSpawner);
	UClass* Z_Construct_UClass_ASDTProjectileSpawner_NoRegister()
	{
		return ASDTProjectileSpawner::StaticClass();
	}
	struct Z_Construct_UClass_ASDTProjectileSpawner_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_SDTProjectileBP_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_m_SDTProjectileBP;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_TimeToShoot_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_m_TimeToShoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_ShotDirection_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_m_ShotDirection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_ShotSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_m_ShotSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_MaxSimultaneousProjectiles_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_m_MaxSimultaneousProjectiles;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASDTProjectileSpawner_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStaticMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "SDTProjectileSpawner.h" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_SDTProjectileBP_MetaData[] = {
		{ "Category", "ActorSpawning" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_SDTProjectileBP = { "m_SDTProjectileBP", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectileSpawner, m_SDTProjectileBP), Z_Construct_UClass_ASDTProjectile_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_SDTProjectileBP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_SDTProjectileBP_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_TimeToShoot_MetaData[] = {
		{ "Category", "SDTProjectileSpawner" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_TimeToShoot = { "m_TimeToShoot", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectileSpawner, m_TimeToShoot), METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_TimeToShoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_TimeToShoot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotDirection_MetaData[] = {
		{ "Category", "SDTProjectileSpawner" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotDirection = { "m_ShotDirection", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectileSpawner, m_ShotDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotDirection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotDirection_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotSpeed_MetaData[] = {
		{ "Category", "SDTProjectileSpawner" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotSpeed = { "m_ShotSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectileSpawner, m_ShotSpeed), METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_MaxSimultaneousProjectiles_MetaData[] = {
		{ "Category", "SDTProjectileSpawner" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_MaxSimultaneousProjectiles = { "m_MaxSimultaneousProjectiles", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectileSpawner, m_MaxSimultaneousProjectiles), METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_MaxSimultaneousProjectiles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_MaxSimultaneousProjectiles_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASDTProjectileSpawner_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_SDTProjectileBP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_TimeToShoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_MaxSimultaneousProjectiles,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASDTProjectileSpawner_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASDTProjectileSpawner>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::ClassParams = {
		&ASDTProjectileSpawner::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASDTProjectileSpawner_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASDTProjectileSpawner()
	{
		if (!Z_Registration_Info_UClass_ASDTProjectileSpawner.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASDTProjectileSpawner.OuterSingleton, Z_Construct_UClass_ASDTProjectileSpawner_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASDTProjectileSpawner.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASDTProjectileSpawner>()
	{
		return ASDTProjectileSpawner::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASDTProjectileSpawner);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTProjectileSpawner_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTProjectileSpawner_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASDTProjectileSpawner, ASDTProjectileSpawner::StaticClass, TEXT("ASDTProjectileSpawner"), &Z_Registration_Info_UClass_ASDTProjectileSpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASDTProjectileSpawner), 1211096660U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTProjectileSpawner_h_304108741(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTProjectileSpawner_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTProjectileSpawner_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
