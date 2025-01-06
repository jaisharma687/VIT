function clearErrors(){
    errors = document.getElementsByClassName('form_error');
    for(let item of errors)
    {
        item.innerHTML = "";
    }
    document.querySelector("#fname").classList.remove("brd-color");
    document.querySelector("#fpass").classList.remove("brd-color");
    document.querySelector("#fcpass").classList.remove("brd-color");
    document.querySelector("#fphone").classList.remove("brd-color");
    document.querySelector("#femail").classList.remove("brd-color");
    document.querySelector("#fabout").classList.remove("brd-color");
}

function topFunction(){
    document.documentElement.scrollTop = 0;
}

function setError(id,error){
    document.querySelector("#form_error_" + id).innerHTML = error;
    if(id=="sex"){
        var r = document.querySelectorAll('input[name="applicant-sex"]');
        for(var i=0;i<r.length;i++){
            r[i].classList.add("radio-input");
        }
    }
    else{
        document.querySelector("#f" + id).classList.add("brd-color");
    }
}

function validateForm(event){
    event.preventDefault();
    var returnval = true;
    clearErrors();
    var name = document.querySelector("#fname").value;
    if(name.length < 5){
        setError("name","* Name must be at least 5 characters long");
        returnval = false;
    }
    var pass = document.querySelector("#fpass").value;
    var regpx = /^[a-zA-Z0-9\.\$!@%\^\?]+$/;
    if(pass.length < 8) {
        setError("pass","* Password must be at least 8 characters long.");
        returnval = false;
    }
    else{
        if(regpx.test(pass) == false){
            setError("pass","Password must have atleast 1 lowercase alphabet, 1 uppercase alphabet, 1 unique character and 1 number.")
            returnval = false
        }
    }
    var cpass = document.querySelector( "#fcpass" ).value;
    if(cpass != pass){
        setError("cpass","* Both Password and Confirm Password must be equal.");
        returnval = false;
    }
    var phone = document.querySelector('#fphone').value;
    if(phone.length!=10){
        setError("phone","* Phone number should be  of length 10.");
        returnval = false;
    }
    else{
        var regphx = /^[0-9]{10}$/;
        if(!regphx.test(phone)){
            setError("phone","* Phone number should only conatain digits.");
            returnval = false;
        }
    }
    var email = document.querySelector('#femail').value;
    var regemx = /^([a-zA-Z0-9\.-]+)@([a-zA-Z0-9-]+).([a-z]{2,20})(.[a-z]{2,20})?$/;
    if (!regemx.test(email) ) {
        setError("email","* Invalid Email Address.");
        returnval = false;
    }
    var text = document.getElementById("fabout").value;
    if(text.length<20){
        setError("about","* About Me should be atleast 20 words long. Please add more information about yourself.");
        returnval = false;
    }
    var sex = document.querySelectorAll('input[name="applicant-sex"]');
    for(var i=0;i<sex.length;i++){
        if(sex[i].checked==true){
            returnval = true;
            break;
        }
    }
    if(!returnval){
        setError("sex","* Please select your gender");
    }
    if(returnval == false){
        topFunction();
    }
    return returnval;
    }

document.addEventListener("submit",validateForm);
document.addEventListener("reset",clearErrors);