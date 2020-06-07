const { default: createZXP } = require("create-zxp");
const path = require("path");
const fs = require("fs");

if (!fs.existsSync("./build")) fs.mkdirSync("./build");
else {
    fs.readdirSync("./build").forEach((path) => {
        fs.unlinkSync("./build/" + path);
    });
}

createZXP({
    inputDirectory: "./extension",
    outputDirectory: "./build",
    tempDir: "./temp",
    version: 1.0,
    extractDirectory: path.join(__dirname, "debug/zxp"),
}).catch((e) => console.error(e));
