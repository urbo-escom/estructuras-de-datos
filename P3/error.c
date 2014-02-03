/*Errores de lectura y escritura*/
char *errIO[ 5 ] =
{ "No se pudo abrir el archivo",
  "Las dimensiones del mapa son muy chicas",
  "Las dimensiones del mapa son muy grandes",
  "Las dimensiones del mapa no concuerdan",
  "El archivo a guardar no se pudo crear" };

void error( char* txt ){
   puts( txt );
   exit( EXIT_FAILURE );
}