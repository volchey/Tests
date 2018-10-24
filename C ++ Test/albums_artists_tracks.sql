# Нужно создать структуру таблиц: Albums, Artists, Tracks.
# В альбоме может быть много треков. У каждого трека может быть один или несколько авторов.
# Нужно написать запрос для выбора альбомов в записи которых учатвовало больше одного исполнителя.

CREATE TABLE Albums (
	AlbumID		int NOT NULL AUTO_INCREMENT,
	AlbumName	varchar(255),
	PRIMARY KEY  (AlbumID)
);

CREATE TABLE Artists (
	ArtistID	int NOT NULL AUTO_INCREMENT,
	ArtistName	varchar(255),
	PRIMARY KEY  (ArtistID)
);

CREATE TABLE Tracks (
	TrackID				int NOT NULL AUTO_INCREMENT,
	TrackName			varchar(255),
	TrackArtistCount	int NOT NULL,
	TrackAlbum			varchar(255),
	PRIMARY KEY         (TrackID)
);

SELECT * FROM Albums WHERE (AlbumName=(SELECT TrackAlbum FROM Tracks)) AND ((SELECT TrackArtistCount FROM Tracks) > 1);