
// Range control
var range_display = document.getElementById("range-display");
var  range_input = document.getElementById("range-value");
range_display.innerHTML = range_input.value;

range_input.oninput = function(){
    range_display.innerHTML = this.value;
}