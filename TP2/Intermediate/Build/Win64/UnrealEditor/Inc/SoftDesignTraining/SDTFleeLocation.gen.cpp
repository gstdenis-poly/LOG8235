// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTFleeLocation.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTFleeLocation() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTFleeLocation_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTFleeLocation();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void ASDTFleeLocation::StaticRegisterNativesASDTFleeLocation()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASDTFleeLocation);
	UClass* Z_Construct_UClass_ASDTFleeLocation_NoRegister()
	{
		return ASDTFleeLocation::StaticClass();
	}
	struct Z_Construct_UClass_ASDTFleeLocation_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASDTFleeLocation_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTFleeLocation_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SDTFleeLocation.h" },
		{ "ModuleRelativePath", "SDTFleeLocation.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASDTFleeLocation_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASDTFleeLocation>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASDTFleeLocation_Statics::ClassParams = {
		&ASDTFleeLocation::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASDTFleeLocation_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTFleeLocation_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASDTFleeLocation()
	{
		if (!Z_Registration_Info_UClass_ASDTFleeLocation.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASDTFleeLocation.OuterSingleton, Z_Construct_UClass_ASDTFleeLocation_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASDTFleeLocation.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASDTFleeLocation>()
	{
		return ASDTFleeLocation::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASDTFleeLocation);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTFleeLocation_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTFleeLocation_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASDTFleeLocation, ASDTFleeLocation::StaticClass, TEXT("ASDTFleeLocation"), &Z_Registration_Info_UClass_ASDTFleeLocation, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASDTFleeLocation), 4001034212U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTFleeLocation_h_1693497539(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTFleeLocation_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_SDTFleeLocation_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
