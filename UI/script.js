
// Range control
var range_display = document.getElementById("range-display");
var  range_input = document.getElementById("range-value");
range_display.innerHTML = range_input.value;

range_input.oninput = function(){
    range_display.innerHTML = this.value;
}

// Time schedule
var set_time = 0;

function showtime(){
    if (set_time == 0){
        set_time = 1;
    } else {
        set_time = 0;
    }
    console.log(set_time);
    if (set_time == 1){
        document.getElementById("time-card").classList.add("time-card-on");
        document.getElementById("topic-schedule").style.color = "var(--black)";
    } else{
        document.getElementById("time-card").classList.remove("time-card-on");
        document.getElementById("topic-schedule").style.color = "var(--orange)";
    }
} 
