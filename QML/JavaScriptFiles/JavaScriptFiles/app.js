var root
var box

function performClick() {
    let max = root.width - box.width
    box.x = (box.x === 0) ? max : 0
}

function swapColor(obj) {
    return obj.pressed ? "orange" : "gray"
}

function startup(croot, cbox) {
    root = croot
    box = cbox
}

function clicked(mouse) {
    performClick()
}
