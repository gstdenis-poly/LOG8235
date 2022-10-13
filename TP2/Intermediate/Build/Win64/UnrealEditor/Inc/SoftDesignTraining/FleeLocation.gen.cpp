// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/FleeLocation.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFleeLocation() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_AFleeLocation_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_AFleeLocation();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void AFleeLocation::StaticRegisterNativesAFleeLocation()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFleeLocation);
	UClass* Z_Construct_UClass_AFleeLocation_NoRegister()
	{
		return AFleeLocation::StaticClass();
	}
	struct Z_Construct_UClass_AFleeLocation_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFleeLocation_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFleeLocation_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FleeLocation.h" },
		{ "ModuleRelativePath", "FleeLocation.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFleeLocation_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFleeLocation>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFleeLocation_Statics::ClassParams = {
		&AFleeLocation::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AFleeLocation_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFleeLocation_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFleeLocation()
	{
		if (!Z_Registration_Info_UClass_AFleeLocation.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFleeLocation.OuterSingleton, Z_Construct_UClass_AFleeLocation_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFleeLocation.OuterSingleton;
	}
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<AFleeLocation>()
	{
		return AFleeLocation::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFleeLocation);
	struct Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_FleeLocation_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_FleeLocation_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFleeLocation, AFleeLocation::StaticClass, TEXT("AFleeLocation"), &Z_Registration_Info_UClass_AFleeLocation, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFleeLocation), 3329130593U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_FleeLocation_h_2042878450(TEXT("/Script/SoftDesignTraining"),
		Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_FleeLocation_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TP2_Source_SoftDesignTraining_FleeLocation_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
