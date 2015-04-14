#include "stdafx.h"
#include "SpaceSystemLoadStructs.h"

KEG_ENUM_DEF(BodyType, BodyType, kt) {
    kt.addValue("planet", BodyType::PLANET);
    kt.addValue("star", BodyType::STAR);
    kt.addValue("gasGiant", BodyType::GAS_GIANT);
}

KEG_ENUM_DEF(ObjectType, ObjectType, kt) {
    kt.addValue("BaryCenter", ObjectType::BARYCENTER);
    kt.addValue("Star", ObjectType::STAR);
    kt.addValue("Planet", ObjectType::PLANET);
    kt.addValue("DwarfPlanet", ObjectType::DWARF_PLANET);
    kt.addValue("Moon", ObjectType::MOON);
    kt.addValue("DwarfMoon", ObjectType::DWARF_MOON);
    kt.addValue("Asteroid", ObjectType::ASTEROID);
    kt.addValue("Comet", ObjectType::COMET);
}

KEG_ENUM_DEF(TrojanType, TrojanType, kt) {
    kt.addValue("L4", TrojanType::L4);
    kt.addValue("L5", TrojanType::L5);
}

KEG_TYPE_DEF_SAME_NAME(SystemBodyKegProperties, kt) {
    kt.addValue("type", keg::Value::custom(offsetof(SystemBodyKegProperties, type), "ObjectType", false));
    kt.addValue("trojan", keg::Value::custom(offsetof(SystemBodyKegProperties, trojan), "TrojanType", false));
    kt.addValue("bodies", keg::Value::array(offsetof(SystemBodyKegProperties, comps), keg::BasicType::C_STRING));
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, par, STRING);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, path, STRING);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, ref, STRING);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, e, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, t, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, a, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, n, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, p, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, i, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, RA, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, dec, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, dist, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, td, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, SystemBodyKegProperties, tf, F64);
}

KEG_TYPE_DEF_SAME_NAME(AtmosphereKegProperties, kt) {
    KEG_TYPE_INIT_ADD_MEMBER(kt, AtmosphereKegProperties, kr, F32);
    KEG_TYPE_INIT_ADD_MEMBER(kt, AtmosphereKegProperties, km, F32);
    KEG_TYPE_INIT_ADD_MEMBER(kt, AtmosphereKegProperties, g, F32);
    KEG_TYPE_INIT_ADD_MEMBER(kt, AtmosphereKegProperties, scaleDepth, F32);
    KEG_TYPE_INIT_ADD_MEMBER(kt, AtmosphereKegProperties, waveLength, F32_V3);
}

KEG_TYPE_DEF_SAME_NAME(PlanetKegProperties, kt) {
    KEG_TYPE_INIT_ADD_MEMBER(kt, PlanetKegProperties, diameter, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, PlanetKegProperties, density, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, PlanetKegProperties, mass, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, PlanetKegProperties, axis, F64_V3);
    KEG_TYPE_INIT_ADD_MEMBER(kt, PlanetKegProperties, angularSpeed, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, PlanetKegProperties, rotationalPeriod, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, PlanetKegProperties, displayName, STRING);
    KEG_TYPE_INIT_ADD_MEMBER(kt, PlanetKegProperties, generation, STRING);
    kt.addValue("atmosphere", keg::Value::custom(offsetof(PlanetKegProperties, atmosphere), "AtmosphereKegProperties", false));
}

KEG_TYPE_DEF_SAME_NAME(StarKegProperties, kt) {
    KEG_TYPE_INIT_ADD_MEMBER(kt, StarKegProperties, surfaceTemperature, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, StarKegProperties, diameter, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, StarKegProperties, density, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, StarKegProperties, mass, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, StarKegProperties, axis, F64_V3);
    KEG_TYPE_INIT_ADD_MEMBER(kt, StarKegProperties, angularSpeed, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, StarKegProperties, displayName, STRING);
}

KEG_TYPE_DEF_SAME_NAME(GasGiantKegProperties, kt) {
    KEG_TYPE_INIT_ADD_MEMBER(kt, GasGiantKegProperties, diameter, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, GasGiantKegProperties, density, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, GasGiantKegProperties, mass, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, GasGiantKegProperties, axis, F64_V3);
    KEG_TYPE_INIT_ADD_MEMBER(kt, GasGiantKegProperties, angularSpeed, F64);
    KEG_TYPE_INIT_ADD_MEMBER(kt, GasGiantKegProperties, oblateness, F32);
    KEG_TYPE_INIT_ADD_MEMBER(kt, GasGiantKegProperties, colorMap, STRING);
    KEG_TYPE_INIT_ADD_MEMBER(kt, GasGiantKegProperties, displayName, STRING);
    kt.addValue("atmosphere", keg::Value::custom(offsetof(GasGiantKegProperties, atmosphere), "AtmosphereKegProperties", false));
}
