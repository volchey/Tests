

# Нужно создать структуру таблиц: Albums, Artists, Tracks.
# В альбоме может быть много треков. У каждого трека может быть один или несколько авторов.
# Нужно написать запрос для выбора альбомов в записи которых учатвовало больше одного исполнителя.

CREATE TABLE Albums (
	AlbumID		int,
	AlbumName	varchar(255)
);

CREATE TABLE Artists (

);

CREATE TABLE Tracks (
	TrackID		int,
	TrackName	varchar(255),
	TrackArtist	varchar(255)
);

SELECT * FROM Albums WHERE ;
