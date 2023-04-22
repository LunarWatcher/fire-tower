#include "Database.hpp"

namespace firetower {

Database::Database() {
    db.exec(R"(
CREATE TABLE IF NOT EXISTS Burnination (
    ID INTEGER PRIMARY KEY AUTOINCREMENT,
    Tags TEXT,
    Completed INTEGER,
    StartedDate DATE,
    EndedDate DATE,
    TotalQuestions INTEGER,
    TotalUsers INTEGER,
    ClosedQuestions INTEGER,
    DeletedQuestions INTEGER,
    EditedQuestions INTEGER
);

CREATE TABLE IF NOT EXISTS BurninationUsers (
    UserID INTEGER,
    BurninationID INTEGER,
    ActionCount INTEGER,
    PRIMARY KEY(UserID, BurninationID)
);

-- Indices are required to speed up SQLite.
-- While of little concern now, and possibly forever (the comment database I have in a different (private) project started
-- struggling at a few hundred thousand entries),
-- there's every chance that the database chagnes to include timed entries, at which point lookup speed matters
CREATE INDEX IF NOT EXISTS ididx ON Burnination(ID);
CREATE INDEX IF NOT EXISTS tagidx ON Burnination(Tags);
)");
}

}
