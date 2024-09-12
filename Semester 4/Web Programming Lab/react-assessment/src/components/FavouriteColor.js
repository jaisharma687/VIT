import React, { useState } from "react";
import ReactDOM from "react-dom";

function FavoriteColor() {
    const [color, setColor] = useState("Red");

    return (
        <>
        <h1>My Favorite Color: {color}</h1>
        <button type="button" onClick={() => setColor("blue")}>Change to blue</button>
        </>
    );
}

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<FavoriteColor />);
