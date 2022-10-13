// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTCollectible.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTCollectible() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTCollectible_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTCollectible();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void ASDTCollectible::StaticRegisterNativesASDTCollectible()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASDTCollectible);
	UClass* Z_Construct_UClass_ASDTCollectible_NoRegister()
	{
		return ASDTCollectible::StaticClass();
	}
	struct Z_Construct_UClass_ASDTCollectible_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_CollectCooldownDuration_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_m_CollectCooldownDuration;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASDTCollectible_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStaticMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTCollectible_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "SDTCollectible.h" },
		{ "ModuleRelativePath", "SDTCollectible.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTCollectible_Statics::NewProp_m_CollectCooldownDuration_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTCollectible.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTCollectible_Statics::NewProp_m_CollectCooldownDuration = { "m_CollectCooldownDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTCollectible, m_CollectCooldownDuration), METADATA_PARAMS(Z_Construct_UClass_ASDTCollectible_Statics::NewProp_m_CollectCooldownDuration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTCollectible_Statics::NewProp_m_CollectCooldownDuration_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASDTCollectible_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTCollectible_Statics::NewProp_m_CollectCooldownDuration,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASDTCollectible_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASDTCollectible>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASDTCollectible_Statics::ClassParams = {
		&ASDTCollectible::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASDTCollectible_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASDTCollectible_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASDTCollectible_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTCollectible_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASDTCollectible()
	{
		if (!Z_Registration_Info_UClass_ASDTCollectible.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASDTCollectible.OuterSingleton, Z_Construct_UClass_ASDTCollectible_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASDTCollectible.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASDTCollectible>()
	{
		return ASDTCollectible::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASDTCollectible);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTCollectible_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTCollectible_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASDTCollectible, ASDTCollectible::StaticClass, TEXT("ASDTCollectible"), &Z_Registration_Info_UClass_ASDTCollectible, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASDTCollectible), 1344748434U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTCollectible_h_1542686086(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTCollectible_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTCollectible_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
