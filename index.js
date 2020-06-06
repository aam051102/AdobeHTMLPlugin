const { default: createZXP } = require("create-zxp");
const path = require("path");

createZXP({
    inputDirectory: path.join(__dirname, "extension"),
    outputDirectory: path.join(__dirname, "build"),
    tempDir: path.join(__dirname, "temp"),
    version: 1.0,
    extractDirectory: path.join(__dirname, "debug/zxp"),
}).catch((e) => console.error(e));

/*
buildoptions { "/Zc:wchar_t-" }
postbuildcommands { "ren $(SolutionDir)extension\\plugin\\lib\\win\\$(TargetName).dll $(SolutionDir)extension\\plugin\\lib\\win\\$(TargetName).fcm" }
*/
