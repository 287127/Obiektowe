CREATE TABLE IF NOT EXISTS Rola (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nazwa TEXT NOT NULL UNIQUE CHECK(nazwa IN ('admin', 'nauczyciel', 'uczen'))
);


CREATE TABLE IF NOT EXISTS Users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL UNIQUE,
    passwrd TEXT NOT NULL,
    rola_id INTEGER,
    FOREIGN KEY (rola_id) REFERENCES Rola(id)
);


