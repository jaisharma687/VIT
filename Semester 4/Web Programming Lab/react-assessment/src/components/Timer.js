import React, { useState, useEffect } from "react";
import ReactDOM from "react-dom";

function Timer() {
    const [count, setCount] = useState(0);

    useEffect(() => {
        const timer = setTimeout(() => {
        setCount((count) => count + 1);
        }, 1000);

        return () => clearTimeout(timer); // Cleanup function to clear the timer on unmount
    }, []); // Empty dependency array to run effect only once on mount

    return <h1>I have rendered {count} times!</h1>;
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Timer />);
