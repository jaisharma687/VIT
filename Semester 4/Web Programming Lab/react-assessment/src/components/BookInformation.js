import React, { useState } from 'react';
import { useForm } from 'react-hook-form';

const BookForm = () => {
    const { register, handleSubmit, reset } = useForm();
    const [books, setBooks] = useState([]);

    const onSubmit = (data) => {
        setBooks([...books, data]);
        reset();
    };

    return (
        <div>
        <form onSubmit={handleSubmit(onSubmit)}>
            <label>Book Title:</label>
            <input type="text" {...register("title", { required: true })} />
            
            <label>Publisher:</label>
            <select {...register("publisher", { required: true })}>
            <option value="publisher1">Publisher 1</option>
            <option value="publisher2">Publisher 2</option>
            <option value="publisher3">Publisher 3</option>
            </select>
            
            <button type="submit">Submit</button>
        </form>

        <table>
            <thead>
            <tr>
                <th>Book Title</th>
                <th>Publisher</th>
            </tr>
            </thead>
            <tbody>
            {books.map((book, index) => (
                <tr key={index}>
                <td>{book.title}</td>
                <td>{book.publisher}</td>
                </tr>
            ))}
            </tbody>
        </table>
        </div>
    );
    };

export default BookForm;
