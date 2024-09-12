import React,{useState} from "react"

export default function TextForm(props) {
    const[text,setText] = useState("");
    const handleUpCLick = ()=>{
        // console.log("Upper case was clicked");
        // setText("Jai Sharma")
        let newText = text.toUpperCase();
        setText(newText);
    }

    const handleLoCLick = ()=>{
        let newText = text.toLowerCase();
        setText(newText);
    }

    const handleOnChange = (event)=>{
        setText(event.target.value);
    }
    // text = "new text"; // wrong way
    //setText("new text"); // correct way
    return (
        <>
        <div className="container">
            <h1>{props.heading}</h1>
            <div className="mb-3">
                <textarea id="myBox" rows="8" value = {text} onChange={handleOnChange} className="form-control"></textarea>
            </div>
            <button className="btn btn-primary mx-3" onClick={handleUpCLick}>Convert to UpperCase</button>
            <button className="btn btn-primary mx-3" onClick={handleLoCLick}>Convert to LowerCase</button>
        </div>
        <div className="container my-3">
            <h1>Your text Summary</h1>
            <p>{text.split(" ").length} words and {text.length} characters.</p>
            <p>{0.008 * text.split(" ").length} Minutes read</p>
            <h2>Preview</h2>
            <p>{text}</p>
        </div>
        </>
    )
}