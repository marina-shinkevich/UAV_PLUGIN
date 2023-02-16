
function setFanState(fan_auto, fan1, fan2) {
    var Ip = fan_auto + (fan1 << 1) + (fan2 << 2)

    return Ip
}
