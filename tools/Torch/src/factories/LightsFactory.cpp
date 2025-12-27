#include "LightsFactory.h"

#include "utils/Decompressor.h"
#include "spdlog/spdlog.h"
#include "Companion.h"

static const std::unordered_map<std::string, LightsType> sLightsType = {
    { "Light", LightsType::Light },     { "Lights1", LightsType::Lights1 }, { "Lights2", LightsType::Lights2 },
    { "Lights3", LightsType::Lights3 }, { "Lights4", LightsType::Lights4 }, { "Lights5", LightsType::Lights5 },
    { "Lights6", LightsType::Lights6 }, { "Lights7", LightsType::Lights7 },
};

static bool validLights(std::string lightsType) {
    if (!sLightsType.contains(lightsType)) {
        std::string supportedLightsType = " ";

        for (const auto& lightType : sLightsType) {
            supportedLightsType = supportedLightsType + lightType.first + (std::string) ", ";
        }

        SPDLOG_ERROR("Invalid lights type {}\n  \
            Please add one of the following Lights type:\n"
                     "{}",
                     lightsType, supportedLightsType);
        return false;
    }
    return true;
}

static int getLightsSize(LightsType lightsType) {
    switch (lightsType) {
        case LightsType::Light:
            return sizeof(LightRaw);
        case LightsType::Lights1:
            return sizeof(Lights1Raw);
        case LightsType::Lights2:
            return sizeof(Lights2Raw);
        case LightsType::Lights3:
            return sizeof(Lights3Raw);
        case LightsType::Lights4:
            return sizeof(Lights4Raw);
        case LightsType::Lights5:
            return sizeof(Lights5Raw);
        case LightsType::Lights6:
            return sizeof(Lights6Raw);
        case LightsType::Lights7:
            return sizeof(Lights7Raw);
        default:
            throw std::runtime_error(
                "Unknown lights type!\nThis is one of those issues that should never really happen.");
            return -1;
    }
}

static void writeLight(LightRaw light, std::ostream& write) {

    // Diffuse
    auto r2 = (int16_t) light.l.col[0];
    auto g2 = (int16_t) light.l.col[1];
    auto b2 = (int16_t) light.l.col[2];

    // Direction
    auto x = (int16_t) light.l.dir[0];
    auto y = (int16_t) light.l.dir[1];
    auto z = (int16_t) light.l.dir[2];

    write << fourSpaceTab << fourSpaceTab;
    write << r2 << ", " << g2 << ", " << b2 << ", " << x << ", " << y << ", " << z << ",\n";

}

static void writeLights1(Lights1Raw lights1, std::ostream& write) {
    // Ambient
    auto r = (int16_t) lights1.a.l.col[0];
    auto g = (int16_t) lights1.a.l.col[1];
    auto b = (int16_t) lights1.a.l.col[2];

    // Diffuse
    auto r2 = (int16_t) lights1.l[0].l.col[0];
    auto g2 = (int16_t) lights1.l[0].l.col[1];
    auto b2 = (int16_t) lights1.l[0].l.col[2];

    // Direction
    auto x = (int16_t) lights1.l[0].l.dir[0];
    auto y = (int16_t) lights1.l[0].l.dir[1];
    auto z = (int16_t) lights1.l[0].l.dir[2];

    SPDLOG_INFO("Read light: {:X} {:X} {:X} {:X} {:X}", r, g, b, r2, g2);

    write << fourSpaceTab << fourSpaceTab;
    write << r << ", " << g << ", " << b << ",\n";
    write << fourSpaceTab << fourSpaceTab;
    write << r2 << ", " << g2 << ", " << b2 << ", " << x << ", " << y << ", " << z << ",\n";

}

static void writeLights2(Lights2Raw lights2, std::ostream& write) {
    // Ambient
    auto r = (int16_t) lights2.a.l.col[0];
    auto g = (int16_t) lights2.a.l.col[1];
    auto b = (int16_t) lights2.a.l.col[2];

    write << fourSpaceTab << fourSpaceTab;
    write << r << ", " << g << ", " << b << ",\n";

    for (int i = 0; i < 2; i++) {
        // Diffuse
        auto r2 = (int16_t) lights2.l[i].l.col[0];
        auto g2 = (int16_t) lights2.l[i].l.col[1];
        auto b2 = (int16_t) lights2.l[i].l.col[2];

        // Direction
        auto x = (int16_t) lights2.l[i].l.dir[0];
        auto y = (int16_t) lights2.l[i].l.dir[1];
        auto z = (int16_t) lights2.l[i].l.dir[2];

        write << fourSpaceTab << fourSpaceTab;
        write << r2 << ", " << g2 << ", " << b2 << ", " << x << ", " << y << ", " << z << ",\n";
    }

}

static void writeLights3(Lights3Raw lights3, std::ostream& write) {
    // Ambient
    auto r = (int16_t) lights3.a.l.col[0];
    auto g = (int16_t) lights3.a.l.col[1];
    auto b = (int16_t) lights3.a.l.col[2];

    write << fourSpaceTab << fourSpaceTab;
    write << r << ", " << g << ", " << b << ",\n";

    for (int i = 0; i < 3; i++) {
        // Diffuse
        auto r2 = (int16_t) lights3.l[i].l.col[0];
        auto g2 = (int16_t) lights3.l[i].l.col[1];
        auto b2 = (int16_t) lights3.l[i].l.col[2];

        // Direction
        auto x = (int16_t) lights3.l[i].l.dir[0];
        auto y = (int16_t) lights3.l[i].l.dir[1];
        auto z = (int16_t) lights3.l[i].l.dir[2];

        write << fourSpaceTab << fourSpaceTab;
        write << r2 << ", " << g2 << ", " << b2 << ", " << x << ", " << y << ", " << z << ",\n";
    }

}

static void writeLights4(Lights4Raw lights4, std::ostream& write) {
    // Ambient
    auto r = (int16_t) lights4.a.l.col[0];
    auto g = (int16_t) lights4.a.l.col[1];
    auto b = (int16_t) lights4.a.l.col[2];

    write << fourSpaceTab << fourSpaceTab;
    write << r << ", " << g << ", " << b << ",\n";

    for (int i = 0; i < 4; i++) {
        // Diffuse
        auto r2 = (int16_t) lights4.l[i].l.col[0];
        auto g2 = (int16_t) lights4.l[i].l.col[1];
        auto b2 = (int16_t) lights4.l[i].l.col[2];

        // Direction
        auto x = (int16_t) lights4.l[i].l.dir[0];
        auto y = (int16_t) lights4.l[i].l.dir[1];
        auto z = (int16_t) lights4.l[i].l.dir[2];

        write << fourSpaceTab << fourSpaceTab;
        write << r2 << ", " << g2 << ", " << b2 << ", " << x << ", " << y << ", " << z << (i == 3 ? "\n" : ",\n");
    }

}

static void writeLights5(Lights5Raw lights5, std::ostream& write) {
    // Ambient
    auto r = (int16_t) lights5.a.l.col[0];
    auto g = (int16_t) lights5.a.l.col[1];
    auto b = (int16_t) lights5.a.l.col[2];

    write << fourSpaceTab << fourSpaceTab;
    write << r << ", " << g << ", " << b << ",\n";

    for (int i = 0; i < 5; i++) {
        // Diffuse
        auto r2 = (int16_t) lights5.l[i].l.col[0];
        auto g2 = (int16_t) lights5.l[i].l.col[1];
        auto b2 = (int16_t) lights5.l[i].l.col[2];

        // Direction
        auto x = (int16_t) lights5.l[i].l.dir[0];
        auto y = (int16_t) lights5.l[i].l.dir[1];
        auto z = (int16_t) lights5.l[i].l.dir[2];

        write << fourSpaceTab << fourSpaceTab;
        write << r2 << ", " << g2 << ", " << b2 << ", " << x << ", " << y << ", " << z << ",\n";
    }

}

static void writeLights6(Lights6Raw lights6, std::ostream& write) {
    // Ambient
    auto r = (int16_t) lights6.a.l.col[0];
    auto g = (int16_t) lights6.a.l.col[1];
    auto b = (int16_t) lights6.a.l.col[2];

    write << fourSpaceTab << fourSpaceTab;
    write << r << ", " << g << ", " << b << ",\n";

    for (int i = 0; i < 6; i++) {
        // Diffuse
        auto r2 = (int16_t) lights6.l[i].l.col[0];
        auto g2 = (int16_t) lights6.l[i].l.col[1];
        auto b2 = (int16_t) lights6.l[i].l.col[2];

        // Direction
        auto x = (int16_t) lights6.l[i].l.dir[0];
        auto y = (int16_t) lights6.l[i].l.dir[1];
        auto z = (int16_t) lights6.l[i].l.dir[2];

        write << fourSpaceTab << fourSpaceTab;
        write << r2 << ", " << g2 << ", " << b2 << ", " << x << ", " << y << ", " << z << ",\n";
    }

}
static void writeLights7(Lights7Raw lights7, std::ostream& write) {
    // Ambient
    auto r = (int16_t) lights7.a.l.col[0];
    auto g = (int16_t) lights7.a.l.col[1];
    auto b = (int16_t) lights7.a.l.col[2];

    write << fourSpaceTab << fourSpaceTab;
    write << r << ", " << g << ", " << b << ",\n";

    for (int i = 0; i < 7; i++) {
        // Diffuse
        auto r2 = (int16_t) lights7.l[i].l.col[0];
        auto g2 = (int16_t) lights7.l[i].l.col[1];
        auto b2 = (int16_t) lights7.l[i].l.col[2];

        // Direction
        auto x = (int16_t) lights7.l[i].l.dir[0];
        auto y = (int16_t) lights7.l[i].l.dir[1];
        auto z = (int16_t) lights7.l[i].l.dir[2];

        write << fourSpaceTab << fourSpaceTab;
        write << r2 << ", " << g2 << ", " << b2 << ", " << x << ", " << y << ", " << z << ",\n";
    }

}

static void writeLights(std::ostream& write, LightsType lightsType, char* lightsPtr) {
    switch (lightsType) {
        case LightsType::Lights1: {
            Lights1Raw lights1 = *(Lights1Raw*) lightsPtr;
            writeLights1(lights1, write);
            break;
        }
        case LightsType::Lights2: {
            Lights2Raw lights2 = *(Lights2Raw*) lightsPtr;
            writeLights2(lights2, write);
            break;
        }
        case LightsType::Lights3: {
            Lights3Raw lights3 = *(Lights3Raw*) lightsPtr;
            writeLights3(lights3, write);
            break;
        }
        case LightsType::Lights4: {
            Lights4Raw lights4 = *(Lights4Raw*) lightsPtr;
            writeLights4(lights4, write);
            break;
        }
        case LightsType::Lights5: {
            Lights5Raw lights5 = *(Lights5Raw*) lightsPtr;
            writeLights5(lights5, write);
            break;
        }

        case LightsType::Lights6: {
            Lights6Raw lights6 = *(Lights6Raw*) lightsPtr;
            writeLights6(lights6, write);
            break;
        }
        case LightsType::Lights7: {
            Lights7Raw lights7 = *(Lights7Raw*) lightsPtr;
            writeLights7(lights7, write);
            break;
        }
    }
}

ExportResult LightsHeaderExporter::Export(std::ostream& write, std::shared_ptr<IParsedData> raw, std::string& entryName,
                                          YAML::Node& node, std::string* replacement) {
    auto light = std::static_pointer_cast<LightsData>(raw)->mLightsPtr;
    LightsType lightType = std::static_pointer_cast<LightsData>(raw)->mLightsType;
    const auto symbol = GetSafeNode(node, "symbol", entryName);
    const auto lightsTypeName = GetSafeNode<std::string>(node, "lights_type");

    if (!validLights(lightsTypeName)) {
        return std::nullopt;
    } else {
        SPDLOG_ERROR("Valid lights in export!\n");
    }

    if (Companion::Instance->IsOTRMode()) {
        write << "static const ALIGN_ASSET(2) char " << symbol << "[] = \"__OTR__" << (*replacement) << "\";\n\n";
        return std::nullopt;
    }

    const auto offset = GetSafeNode<uint32_t>(node, "offset");
    const auto searchTable = Companion::Instance->SearchTable(offset);

    if (searchTable.has_value()) {
        const auto [name, start, end, mode, index_size] = searchTable.value();

        if (start != offset) {
            return std::nullopt;
        }

        write << "extern " << lightsTypeName << name << "[];\n";
    } else {
        write << "extern " << lightsTypeName << symbol << ";\n";
    }
    return std::nullopt;
}

ExportResult LightsCodeExporter::Export(std::ostream& write, std::shared_ptr<IParsedData> raw, std::string& entryName,
                                        YAML::Node& node, std::string* replacement) {
    auto light = std::static_pointer_cast<LightsData>(raw)->mLightsPtr;
    LightsType lightType = std::static_pointer_cast<LightsData>(raw)->mLightsType;
    auto symbol = GetSafeNode(node, "symbol", entryName);
    const auto offset = GetSafeNode<uint32_t>(node, "offset");
    const auto lightsTypeName = GetSafeNode<std::string>(node, "lights_type");
    const auto searchTable = Companion::Instance->SearchTable(offset);

    if (!validLights(lightsTypeName)) {
        return std::nullopt;
    } else {
        SPDLOG_ERROR("Valid lights in export!\n");
    }

    if (searchTable.has_value()) {
        const auto [name, start, end, mode, index_size] = searchTable.value();

        if (start == offset) {
            write << " " << lightsTypeName << name << "[] = {\n";
        }

        write << fourSpaceTab << "gdSPDef(\n" << lightsTypeName;
        writeLights(write, lightType, light);
        write << fourSpaceTab << "),\n";

        if (end == offset) {
            write << "};\n\n";
        }

    } else {
        write << lightsTypeName << " " << symbol << " = gdSPDef" << lightsTypeName << "(\n";

        writeLights(write, lightType, light);

        write << ");\n\n";
    }
    return std::nullopt;
}

ExportResult LightsBinaryExporter::Export(std::ostream& write, std::shared_ptr<IParsedData> raw, std::string& entryName,
                                          YAML::Node& node, std::string* replacement) {
    auto light = std::static_pointer_cast<LightsData>(raw)->mLightsPtr;
    auto lightsType = std::static_pointer_cast<LightsData>(raw)->mLightsType;
    auto writer = LUS::BinaryWriter();
    WriteHeader(writer, Torch::ResourceType::Lights, 0);
    int lightsSize = getLightsSize(lightsType);
        
    SPDLOG_ERROR("Lights type {} size {} !\n", (int)lightsType, lightsSize);
    writer.Write(reinterpret_cast<char*>(light), lightsSize);
    writer.Finish(write);
    writer.Close();
    return std::nullopt;
}

std::optional<std::shared_ptr<IParsedData>> LightsFactory::parse(std::vector<uint8_t>& buffer, YAML::Node& node) {
    const auto lightsType = GetSafeNode<std::string>(node, "lights_type");

    if (!validLights(lightsType)) {
        return std::nullopt;
    } else {
        SPDLOG_ERROR("Valid lights!\n");
    }

    LightsType type = sLightsType.at(lightsType);

    auto decoded = Decompressor::AutoDecode(node, buffer);
    auto [_, segment] = Decompressor::AutoDecode(node, buffer);

    int lightsSize = getLightsSize(type);
    SPDLOG_ERROR("Lights type {} size {} !\n", (int)type, lightsSize);

    char* lightPtr = (char*) std::malloc(lightsSize);


    LUS::BinaryReader reader(segment.data, lightsSize);
    reader.Read((char*) lightPtr, lightsSize);
    return std::make_shared<LightsData>(lightPtr, type);
}
