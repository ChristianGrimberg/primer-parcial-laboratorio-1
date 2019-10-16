## Desarrollar en ANSI C

Se necesita administrar los alquileres de juegos infantiles, y para ello se deberá realizar un programa de acuerdo a lo siguiente:

### Juego

* Código
* Descripción
* Importe
* id de Categoría

### Categoría

* id
* Descripción (máximo 51 caracteres) (mesa, azar, estrategia, salón, magia)

### Cliente

* Código (autoincremental)
* Nombre (máximo 51 caracteres) __Validar__
* Apellido (máximo 51 caracteres) __Validar__
* Sexo __Validar__
* Teléfono (máximo 21 caracteres) __Validar__

### Alquileres

* Código de Alquiler (autoincremental)
* Código de juego __Validar__
* Código de cliente __Validar__
* Fecha (estructura) (dia, mes, año)

#### Clientes

1. __Altas:__ No es necesario el ingreso de todos los clientes.
1. __Modificar:__ Se ingresará el ___Código de Cliente___, permitiendo en un submenu modificar:
    * Nombre
    * Domicilio
    * Teléfono
1. __Baja:__ Se ingresará el ___Código de Cliente___ y se realizará la baja lógica.
1. __Listar:__ Hacer un único listado de todos los Clientes ordenados por apellido y nombre.

#### Alquileres

Se dará de alta cada ocurrencia de alquiler, relacionando Juego-Cliente, Fecha y Código de Alquiler.

* __Listar alquileres__

##### NOTAS

1. Se deberá desarrollar bibliotecas por cada entidad, las cuáles contendrán las funciones Alta, Baja, Modificar y Listar.
1. Las validaciones deberán estar en una biblioteca aparte.
1. El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo de la cátedra.

#### Informes

1. Mostrar Juegos de categoría de mesa.
1. Mostrar los alquileres efectuados por algún cliente seleccionado.
1. Mostrar el total de todos los importes pagados por el cliente seleccionado.
1. Listar los clientes que no alquilaron juegos.
1. Listar los juegos que no han sido alquilados.
