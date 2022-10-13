// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTProjectile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTProjectile() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTProjectile_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTProjectile();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void ASDTProjectile::StaticRegisterNativesASDTProjectile()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASDTProjectile);
	UClass* Z_Construct_UClass_ASDTProjectile_NoRegister()
	{
		return ASDTProjectile::StaticClass();
	}
	struct Z_Construct_UClass_ASDTProjectile_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_TimeToLive_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_m_TimeToLive;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASDTProjectile_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStaticMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectile_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "SDTProjectile.h" },
		{ "ModuleRelativePath", "SDTProjectile.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectile_Statics::NewProp_m_TimeToLive_MetaData[] = {
		{ "Category", "SDTProjectile" },
		{ "ModuleRelativePath", "SDTProjectile.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTProjectile_Statics::NewProp_m_TimeToLive = { "m_TimeToLive", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectile, m_TimeToLive), METADATA_PARAMS(Z_Construct_UClass_ASDTProjectile_Statics::NewProp_m_TimeToLive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectile_Statics::NewProp_m_TimeToLive_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASDTProjectile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectile_Statics::NewProp_m_TimeToLive,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASDTProjectile_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASDTProjectile>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASDTProjectile_Statics::ClassParams = {
		&ASDTProjectile::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASDTProjectile_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectile_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASDTProjectile_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectile_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASDTProjectile()
	{
		if (!Z_Registration_Info_UClass_ASDTProjectile.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASDTProjectile.OuterSingleton, Z_Construct_UClass_ASDTProjectile_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASDTProjectile.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASDTProjectile>()
	{
		return ASDTProjectile::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASDTProjectile);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTProjectile_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTProjectile_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASDTProjectile, ASDTProjectile::StaticClass, TEXT("ASDTProjectile"), &Z_Registration_Info_UClass_ASDTProjectile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASDTProjectile), 60794892U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTProjectile_h_74440681(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTProjectile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTProjectile_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
