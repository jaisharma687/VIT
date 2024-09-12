import React from "react";
import ReactDOM from "react-dom";

// Define the School component
function School(props) {
    return (
        <div>
            <h1>School Name: {props.name.BName}</h1>
            <p>Branch Strength: {props.name.BStrength}</p>
        </div>
    );
}

// Define the Branch component
function Branch() {
    const BInfo = { BName: "BCE", BStrength: 1200 };
    return <School name={BInfo} />;
}

// Create a root element and render the Branch component
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Branch />);
