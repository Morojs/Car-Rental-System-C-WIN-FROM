CREATE DATABASE "location_voitures"
    WITH 
    OWNER = postgres
    ENCODING = 'UTF8'
    LC_COLLATE = 'Arabic_Saudi Arabia.1256'
    LC_CTYPE = 'Arabic_Saudi Arabia.1256'
    TABLESPACE = pg_default
    CONNECTION LIMIT = -1;
	

--TABLES
CREATE TABLE public.administrateur
(
    login character varying(30) COLLATE pg_catalog."default" NOT NULL,
    password character varying(30) COLLATE pg_catalog."default",
    CONSTRAINT administrateur_pkey PRIMARY KEY (login)
)
WITH (
    OIDS = FALSE
)
TABLESPACE pg_default;

ALTER TABLE public.administrateur
    OWNER to postgres;
	
CREATE TABLE public.client
(
    cin character varying(30),
    nom character varying(30) COLLATE pg_catalog."default" NOT NULL,
    prenom character varying(30) COLLATE pg_catalog."default" NOT NULL,
    adresse character varying(100) COLLATE pg_catalog."default" NOT NULL,
    telephone integer NOT NULL,
    CONSTRAINT client_pkey PRIMARY KEY (cin)
)
WITH (
    OIDS = FALSE
)
TABLESPACE pg_default;

ALTER TABLE public.client
    OWNER to postgres;
	

CREATE TABLE public.voiture
(
    matricule character varying(30) COLLATE pg_catalog."default" NOT NULL,
    modele character varying(30) COLLATE pg_catalog."default",
    marque character varying(30) COLLATE pg_catalog."default",
    nbr_stock integer,
    tarif double precision,
    CONSTRAINT voiture_pkey PRIMARY KEY (matricule)
)
WITH (
    OIDS = FALSE
)
TABLESPACE pg_default;

ALTER TABLE public.voiture
    OWNER to postgres;


CREATE TABLE public.location
(
	num_loc character varying(30) unique,
    client character varying(30) COLLATE pg_catalog."default" NOT NULL,
    voiture character varying(30) COLLATE pg_catalog."default" NOT NULL,
    duree integer,
    date_debut date,
    date_fin date,
    CONSTRAINT location_pkey PRIMARY KEY (client, voiture,num_loc),
    CONSTRAINT fk_client FOREIGN KEY (client)
        REFERENCES public.client (cin) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION,
    CONSTRAINT fk_voiture FOREIGN KEY (voiture)
        REFERENCES public.voiture (matricule) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)
WITH (
    OIDS = FALSE
)
TABLESPACE pg_default;

ALTER TABLE public.location
    OWNER to postgres;



CREATE TABLE public.penalisation
(
    id_penalisation character varying(30) COLLATE pg_catalog."default",
    etat character varying(30) COLLATE pg_catalog."default",
    raison character varying(30) COLLATE pg_catalog."default",
    montant double precision,
    retourvoiture character varying(30) COLLATE pg_catalog."default",
    CONSTRAINT fk_retourvoiture FOREIGN KEY (retourvoiture)
        REFERENCES public.voiture (matricule) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)
WITH (
    OIDS = FALSE
)
TABLESPACE pg_default;

ALTER TABLE public.penalisation
    OWNER to postgres;
	




CREATE TABLE public.facture
(
    id_facture integer NOT NULL DEFAULT nextval('facture_id_facture_seq'::regclass),
    status character varying(30) COLLATE pg_catalog."default",
    date_facture date,
    montant double precision,
    location integer,
    CONSTRAINT facture_pkey PRIMARY KEY (id_facture),
    CONSTRAINT fk_location FOREIGN KEY (location)
        REFERENCES public.location (id_location) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)
WITH (
    OIDS = FALSE
)
TABLESPACE pg_default;

ALTER TABLE public.facture
    OWNER to postgres;
	
	

--POSTGRES PROC
CREATE OR REPLACE PROCEDURE public.ajouter_client(
	character varying,
	character varying,
	character varying,
	character varying,
	integer)
LANGUAGE 'plpgsql'

AS $BODY$
BEGIN
     insert into client values ($1,$2,$3,$4,$5);
     COMMIT;
END;
$BODY$;


CREATE OR REPLACE PROCEDURE public.supprimer_client(
	character varying)
LANGUAGE 'plpgsql'

AS $BODY$
BEGIN
     delete from client where id_client=cast($1 as int);
     COMMIT;
END;
$BODY$;


CREATE OR REPLACE PROCEDURE public.supprimer_client(
	character varying)
LANGUAGE 'plpgsql'

AS $BODY$
BEGIN
     delete from client where cin=$1
     COMMIT;
END;
$BODY$;


CREATE OR REPLACE PROCEDURE public.ajouter_voiture(
	character varying,
	character varying,
	character varying,
	integer,
	double precision)
LANGUAGE 'plpgsql'

AS $BODY$
BEGIN
     insert into voiture values ($1,$2,$3,$4,$5);
     COMMIT;
END;
$BODY$;

CREATE OR REPLACE PROCEDURE public.modifier_voiture(
	character varying,
	character varying,
	character varying,
	integer,
	double precision)
LANGUAGE 'plpgsql'

AS $BODY$BEGIN
     update voiture set modele=$2,marque=$3,nbr_stock=cast($4 as integer),tarif=cast($5 as float) where matricule=$1;
     COMMIT;
END;
$BODY$;


CREATE OR REPLACE PROCEDURE public.supprimer_voiture(
	character varying)
LANGUAGE 'plpgsql'

AS $BODY$
BEGIN
     delete from voiture where matricule=$1;
     COMMIT;
END;
$BODY$;

--POSTGRES FUNCTION
CREATE OR REPLACE FUNCTION public.existe(
	character varying,
	character varying)
    RETURNS bigint
    LANGUAGE 'sql'

    COST 100
    IMMUTABLE STRICT 
AS $BODY$select count(*) as existe from administrateur where login=$1 and password=$2;$BODY$;

ALTER FUNCTION public.existe(character varying, character varying)
    OWNER TO postgres;


CREATE OR REPLACE FUNCTION public.existeclient(
	character varying(30))
    RETURNS bigint
    LANGUAGE 'sql'

    COST 100
    IMMUTABLE STRICT 
AS $BODY$select count(*) as existe from client where cin=$1;$BODY$;

ALTER FUNCTION public.existeclient(character varying(30))
    OWNER TO postgres;
	
CREATE OR REPLACE FUNCTION public.existevoiture(
	character varying)
    RETURNS bigint
    LANGUAGE 'sql'

    COST 100
    IMMUTABLE STRICT 
AS $BODY$select count(*) as existe from voiture where matricule=$1;$BODY$;

ALTER FUNCTION public.existevoiture(character varying)
    OWNER TO postgres;

CREATE OR REPLACE FUNCTION public.get_voiture(
	arg character varying)
    RETURNS TABLE(matri character varying, mdl character varying, mrq character varying, nbrstk integer, trf double precision) 
    LANGUAGE 'plpgsql'

    COST 100
    VOLATILE 
    ROWS 1000
AS $BODY$
BEGIN
	RETURN QUERY SELECT
		*
	FROM
		voiture
	WHERE
		matricule=$1;
END; $BODY$;

ALTER FUNCTION public.get_voiture(character varying)
    OWNER TO postgres;


CREATE OR REPLACE FUNCTION public.rowscountclient(
	)
    RETURNS bigint
    LANGUAGE 'sql'

    COST 100
    IMMUTABLE STRICT 
AS $BODY$select count(*) as nbrlignes from client $BODY$;

ALTER FUNCTION public.rowscountclient()
    OWNER TO postgres;

CREATE OR REPLACE FUNCTION public.rowscountvoiture(
	)
    RETURNS bigint
    LANGUAGE 'sql'

    COST 100
    IMMUTABLE STRICT 
AS $BODY$select count(*) as nbrlignes from voiture $BODY$;

ALTER FUNCTION public.rowscountvoiture()
    OWNER TO postgres;

CREATE OR REPLACE FUNCTION public.get_client(
	arg character varying)
    RETURNS TABLE(cin character varying, nom character varying, prenom character varying, adresse character varying, telephone integer) 
    LANGUAGE 'plpgsql'

    COST 100
    VOLATILE 
    ROWS 1000
AS $BODY$
BEGIN
	RETURN QUERY SELECT
		*
	FROM
		client
	WHERE
		cin=$1;
END; $BODY$;

ALTER FUNCTION public.get_client(character varying)
    OWNER TO postgres;

CREATE OR REPLACE PROCEDURE public.ajouter_location(
	character varying,
	character varying,
	integer,
	date,
    date)
LANGUAGE 'plpgsql'

AS $BODY$
BEGIN
     insert into location values ((select rowscountlocation()+1),$1,$2,$3,$4,$5);
     COMMIT;
END;
$BODY$;