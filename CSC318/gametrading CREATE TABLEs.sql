USE gametrading;

CREATE TABLE Trade (
	TradeID			INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
	User1_ID		INT NOT NULL,
	User2_ID		INT NOT NULL,
	Game1_ID		INT NOT NULL,
	Game2_ID		INT NOT NULL,
	FOREIGN KEY (User1_ID) REFERENCES User (UserID),
	FOREIGN KEY (User2_ID) REFERENCES User (UserID),
	FOREIGN KEY (GAME1_ID) REFERENCES User (GameID),
	FOREIGN KEY (GAME2_ID) REFERENCES User (GameID)
) ENGINE=INNODB;
CREATE TABLE Game (
	GameID			INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
	Title			VARCHAR(200),
	Publisher		VARCHAR(200) NOT NULL,
	Developer		VARCHAR(200) NOT NULL,
	Series			VARCHAR(200) NOT NULL,
	PlatformID		INT NOT NULL,
	ESRB			VARCHAR(200) NOT NULL,
	ArtURL			VARCHAR(200) NOT NULL,
	AmazonURL		VARCHAR(200) NOT NULL,
	FOREIGN KEY (PlatformID) REFERENCES Platform (PlatformID)
) ENGINE=INNODB;
CREATE TABLE Platform (
	PlatformID		INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
	Name			VARCHAR(200)
) ENGINE=INNODB;
CREATE TABLE TradeMessage(
	TradeMessageID	INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
	TradeID			INT NOT NULL,
	Text			VARCHAR(255) NOT NULL,
	FOREIGN KEY (TradeID) REFERENCES Trade (TradeID)
) ENGINE=INNODB;
CREATE TABLE DesiredGame (
	UserID		INT NOT NULL,
	GameID		INT NOT NULL,
	PRIMARY KEY (UserID, GameID),
	FOREIGN KEY (UserID) REFERENCES User (UserID),
	FOREIGN KEY (GameID) REFERENCES Game (GameID)
) ENGINE=INNODB;
CREATE TABLE OwnedGame (
	UserID		INT NOT NULL,
	GameID		INT NOT NULL,
	PRIMARY KEY (UserID, GameID),
	FOREIGN KEY (UserID) REFERENCES User (UserID),
	FOREIGN KEY (GameID) REFERENCES Game (GameID)
) ENGINE=INNODB;

CREATE PROCEDURE GenerateTrades(
	IN InitiatingUserID INT,
	IN DesiredGameID INT
)
BEGIN
	DECLARE userid INT DEFAULT 0;
	DECLARE gameid INT DEFAULT 0;
	--WHILE 
	--Find  users offering desired game
	SELECT UserID into userid
	FROM OwnedGame Join DesiredGame
	WHERE OwnedGame.GameID = DesiredGameID
	AND 
	--Check them against initiating user's owned games
	--If match is found, generate a trade
	INSERT INTO Trade
	VALUES (
		InitiatingUserID,
		userid,
		DesiredGameID,
		gameid
	);
	--Else we're done
END;
