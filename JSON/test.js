const fs = require('fs')
const path = require('path')
const a = fs.readFileSync(path.join(__dirname, "JsonEx.json"))
const b = JSON.parse(a) // 역직렬화
console.log(b)
console.log(typeof(b))
const c = JSON.stringify(b) // 직렬화
console.log(c)
console.log(typeof(c)) 