import React, { useState } from "react";
import ReactDOM from "react-dom";

function ControlledComponent() {
  // Define state for the input value
    const [inputValue, setInputValue] = useState('');

    // Define a function to handle changes in the input
    const handleChange = (event) => {
        setInputValue(event.target.value);
    };

    // Render the controlled input and display the input value
    return (
        <form>
        <label>Input Value:
            <input type="text" value={inputValue} onChange={handleChange} />
        </label>
        <p>Input Value: {inputValue}</p>
        </form>
    );
}

// Create a root element and render the ControlledComponent component
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<ControlledComponent />);
