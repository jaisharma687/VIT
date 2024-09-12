import React, { useState } from "react";
import ReactDOM from "react-dom";

function FavoriteLang() {
    const [Lang, setLang] = useState("JS");
    return (
        <button type="button" onClick={() => setLang("Java")}>Java</button>
    );
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<FavoriteLang />);
