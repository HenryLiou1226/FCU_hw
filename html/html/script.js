let button = document.getElementById('btn');
let button2 = document.getElementById('refresh');
let img1 = document.getElementById('gif1');
button2.style.display = 'none';
img1.style.display = 'none';
var input = document.getElementById("sex");
input.addEventListener("keypress", function(event) {
  if (event.key === "Enter") {
    event.preventDefault();
    document.getElementById("btn").click();
  }
});
button.addEventListener('click', () => {
    const height = parseInt(document.getElementById('height').value);
    const weight = parseInt(document.getElementById('weight').value);
    const age = parseInt(document.getElementById('age').value);
    const sex = parseInt(document.getElementById('sex').value);
    const result = document.getElementById('output');
    const bmi = (weight / ((height*height)/10000)).toFixed(2);
    const bmr = (9.99*weight+6.25*height-4.92*age+(166*sex-161)).toFixed(2);
    if(height < 1 || age < 1 || sex < 0 || weight < 1)
    {
        var music = new Audio('audio3.mp3');
        img1.style.display = 'block';
        result.innerHTML = '<br>錯誤X_X';
        music.play();
    }
    else if(bmi < 18.5){
        if (sex>1){
            var music = new Audio('WTF.mp3');  
        }
        else{
            var music = new Audio('audio1.mp3');
        }
        music.play();
        result.innerHTML = '您的BMI為過輕範圍 : ' + bmi + '<br>BMR :' + bmr;
    }else if(bmi >= 18.5 && bmi < 24){
        if (sex>1){
            var music = new Audio('WTF.mp3');  
        }
        else{
            var music = new Audio('audio2.mp3');
        }
        music.play();
        result.innerHTML = '您的BMI為正常範圍 : ' + bmi + '<br>BMR :' + bmr;
    }else{
        if (sex>1){
            var music = new Audio('WTF.mp3');  
        }
        else{
            var music = new Audio('audio1.mp3');
        }
        music.play();
        result.innerHTML = '您的BMI為過重範圍 : ' + bmi + '<br>BMR :' + bmr;
    }
    button.style.display = 'none';
    button2.style.display = 'block';
});
const reloadtButton = document.querySelector("#reload");
    function reload() {
        reload = location.reload();
    }
    reloadButton.addEventListener("click", reload, false);