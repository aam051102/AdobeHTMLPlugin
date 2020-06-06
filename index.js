const { default: createZXP } = require("create-zxp");
const path = require("path");

createZXP({
    inputDirectory: "./extension",
    outputDirectory: "./build",
    tempDir: "./temp",
    version: 1.0,
    extractDirectory: path.join(__dirname, "debug/zxp"),
}).catch((e) => console.error(e));
