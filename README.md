<div align="center">
    <h1>ft_datalib</h1>
</div>

```mermaid
flowchart LR
    lst(*lst) -.-> l1
    subgraph Single Linked List
        l1(first) --> l2(n) --> l3(last)
    end
    
    dll(*dll) -.-> d1
    subgraph Doubly Linked List
        d1(first)
        d2(n)
        d3(last)
        d1 --> d2 --> d3
        d3 --> d2 --> d1
    end

    que(*que) -.-> q1
    subgraph Qeue
        q1(first) --> q2(...) --> q3(last)
    end

    stk(*stk) -.-> s1
    subgraph Stack
        s1(first) --> s2(...)
    end
```

<div align="center">
    <p>Porque las listas no son suficientes.</p>
</div>

---

# I. Introducción

Las **estructuras de datos** son una parte fundamental de cualquier lenguaje de programación, y en este proyecto vas a aprender a implementarlas y a usarlas; concretamente, programarás:

**Listas Doblemente Enlazadas**  
La hermana mayor de las Listas Enlazadas.  
Aquí podrás moverte tanto hacia adelante como hacia atrás.

**Colas**  
La hermana pequeña de las listas; son de tipo FIFO (*First In, First Out*).  
Aquí solo importan el primer y último elemento, el resto no son relevantes.

**Pilas**  
La hermana pequeña... ¿de las Colas? Yo que sé; son de tipo LIFO (*Last In, First Out*).  
Aquí solo importa el último elemento, el resto se *apilan* después.



# II. Instrucciones generales

Este proyecto seguirá la misma dinámica que cualquier otro proyecto del *cursus*: reglas del *Makefile*, *Norma\**, etc; no obstante, para este proyecto en particular se añadirá algo nuevo, **un buen uso de Git y GitHub**:
- **Se debe aplicar el *Flujo de Trabajo de Git* al desarrollo.**
- **Se deben usar los recursos de GitHub para gestionar el proyecto.**
- Se realizará en equipos de 3 personas, formados por aquellos en la misma fila.

> Será necesario repartir las tareas del proyecto entre los miembros del equipo para poder terminarlo a tiempo.



# III. Resultados esperados

**Un uso correcto de Git y GitHub durante el desarrollo del proyecto.**  
Este taller no trata sobre *lenguaje C*; así que lo importante no será el resultado final, sino el proceso.
Se espera un repositorio que contenga:
- ***Commits*** relevantes y estructurados.
- **Ramas** bien definidas que reflejen trabajo en equipo.
- ***Issues*** y ***milestones*** que agrupen tareas.
- ***Projects*** que gestionen las tareas.
- ***Pull requests*** que reflejen la revisión de código.

**Aprendizaje sobre estructuras de datos.**  
Saber implementar y manejar estructuras de datos es algo increíblemente útil en cualquier lenguaje de programación.

Esto lo he dicho ya, ¿no? Bueno, es que son **muy importantes**.



# IV. Ejercicios

## Antes de empezar

Este proyecto está estructurado de una forma distinta a la que podrías estar acostumbrado: lee detenidamente este apartado antes de empezar a trabajar.

**Todo el código necesario ya está programado en *recursos.md***, por lo que para realizar las tareas, solo tendrás que colocarlo adecuadamente o bien realizar pequeñas modificaciones sobre un código que ya hayas usado

---

**Estructura del repositorio.**  
Este proyecto solo contiene la carpeta *00-projects-template*, que se corresponde con un proyecto en C totalmente preparado y funcional una vez se añada el código necesario.

Esa carpeta actuará de plantilla, cada equipo copiará


## Parte Obligatoria

### 00 - Preparación

Ejecuta el siguiente comando (si no lo has hecho nunca) para evitar problemas en el desarrollo:
```shell
git config --global merge.ff false
```

> Esto desactiva los *merges fast-foward*, algo que podría confundir a los recién llegados a Git.

**Cread un equipo de 3 personas**: vuestro líder será el estudiante sentado en el centro de la fila, y el resto de miembros serán los que estén a su izquierda y a su derecha; dáos la mano, un par de besos, o lo que proceda.

El líder prepará el repositorio de GitHub del equipo, por lo que deberá:
1. Hacer un *fork* de este repositorio, **incluyendo todas las ramas**.
2. Invitar al resto del equipo como colaboradores (*Settings > Collaborators*).
3. Activar la pestaña de *Issues*, también en *Settings* (desactivada por defecto por algún motivo).

Aún no vamos a empezar a *programar*, así que, ¡manitas quietas! Nada de clonar el repositorio.


### 01 - Planificación

No hay prisa, pensemos las cosas antes de empezar a trabajar.

El siguiente diagrama representa un ejemplo del uso de *Projects*, *Issues* y *Milestones*, todo vinculado:

```mermaid
flowchart TB
    subgraph Proyectos
        P1(Project I)
        P2(Project II)
        P3(ProjectIII)
    end

    subgraph Repositorio A 
        direction TB

        subgraph Tareas A
            direction LR

            I1(Issue 1)
            I2(Issue 2)
            I3(Issue 3)
            I4(Issue 4)
            I5(Issue 5)
            I6(Issue 6)
        end

        subgraph Hitos A
            direction LR

            M1(Milestone 1)
            M2(Milestone 2)
        end
        
        I1 & I2 --- M1
        I3 & I4 & I5 --- M2
    end

    subgraph Repositorio B 
        direction TB

        subgraph Tareas B
            direction LR

            I7(Issue 7)
            I8(Issue 8)
        end
    end

    P1 -.- I1 & I2 & I3
    P2 -.- I4 & I5 & I6
    P3 -.- I6 & I7 & I8
    
```

Observa en el diagrama de ejemplo que los *Projects* son independientes a los Repositorios, al contrario de lo que pasa con los *Issues* y los *Milestones*; esto permite que un *Project* pueda contener recursos de distintos repositorios, pero un repositorio solo puede contener *Issues* y *Milestones* propios.

---

El dueño del repositorio -es decir, el líder- deberá:
- Crear un *Project* público para organizar el trabajo con al menos 2 vistas: tabla (Table) y tablero Kanban (Board).
- Añadir al resto de miembros como colaboradores, igual que pasó con el *fork*.

Una vez hecho eso, **observad los archivos que tenéis**: creo que es evidente que para que el código compile y se ejecute, tendréis que completar las funciones que actualmente se encuentran vacías (todas, excepto los *\*_print.c*); y por otra parte, también podéis observar que para cada estructura de datos hay varios archivos, por lo que quizás sea buena idea organizar el proyecto de la siguiente forma:
1. Completar un fichero (un *Issue*).
2. Varios ficheros completan una estructura de datos (un *Milestone*).
3. Varias estructuras de datos completan el proyecto (¡fin del taller!).

Dicho esto, y usando el *Project* que habéis creado:
1. Cread un *Milestone* para cada estructura de datos (con o sin fecha).
2. Cread los *Issues* "Planificar las tareas" (asignado al líder) y "Añadir Libft como submódulo".
3. Cread un *Issue* por cada fichero que haya que completar y asignadle el *Milestone* y *Project* correspondiente.
4. Repartid las tareas de forma que cada uno se encargue de una estructura de datos.
5. Quizás quieras ver el bonus antes de seguir.

> **NOTA:** por supuesto, toda esta información tiene que estar vinculada.  


### 02 - Demostración de `push` + `pull`

Antes de que os pongáis manos a la obra, vais a hacer vosotros mismos un pequeño ejemplo sobre cómo váis a publicar y descargar cambios entre varios miembros del equipo: una versión reducida, simple y básica, luego usaremos los gloriosos *Pull Requests*.

El repositorio ya está listo:
- Todos debéis clonar el repositorio. **No sigáis hasta que no lo hayáis hecho**.

El líder y solo el líder, hará un pequeño-gran cambio:
1. Duplicar la carpeta *projects-template* en la rama `develop`.
2. Renombrar la copia como ***<estud.1>-<estud.2>-<estud.3>*** (usuarios en la intra).
3. Subir los cambios a la rama `develop` remota, usando `git push`.

Ahora, el resto de miembros deberían tener ese cambio disponible para actualizar sus repositorios.

Ejemplo de la salida de un `git status` con un cambio disponible:
```
On branch develop
Your branch is behind 'origin/develop' by 1 commit.
  (use "git pull" to update your local branch)

(...)
```

Una vez el líder haya subido los cambios, el resto de miembros deberán:
1. Comprobar que existe un cambio en el repositorio remoto con `git status`*.
2. Actualizar la rama `develop` usando `git pull`. **No sigáis hasta que no lo hayáis hecho**.

\* También puedes usar el alias que creaste en la práctica del primer taller.

> **Nota:** asumid que el resto de ejercicios se realizarán sobre dicha carpeta, correspondiente al proyecto de vuestro equipo.


### 03 - El submódulo *Libft*

Muy posiblemente hayáis estado copiando-y-pegando vuestra librería *Libft* en vuestros proyectos, o peor aún, solo sus funciones; ahora ha llegado el momento de convertirnos en seres eficientes y usar un submódulo.

Y solo por si acaso, vamos a ver si de verdad habéis pillado eso de subir y descargar cambios del repositorio remoto.

Alguien distinto al líder deberá ejecutar lo siguiente, **dentro de la carpeta del equipo**:
```shell
git submodule add git@github.com:15Galan/Libft.git
mv ../.gitmodules .
git add ../.gitmodules .
git commit
git push
```

Eso añade [mi Libft](https://github.com/15Galan/Libft) como submódulo; deberías tener la carpeta *Libft* y el archivo *.gitmodules* en la carpeta del equipo.

> He decidido dejaros los comandos para evitar confusiones, ya que Git funciona con *.gitmodules* en la raíz y para este taller, necesitamos moverlo a cada carpeta de equipo.

Dicho esto, volved a repetir el procedimiento anterior donde un miembro sube el cambio y el resto los descarga.

Observad que la carpeta ***Libft*** recibida debería estar vacía, y eso es correcto, ya que un submódulo no contiene archivos, sino una referencia para clonar un repositorio; tendréis que **inicializar el submódulo para poder usarlo**.


### 04 - Implementación

Ya está todo listo para empezar el proyecto, y también para terminarlo, porque ya solo queda una última cosa por hacer: programar las funciones.

**Cada miembro creará una rama para trabajar en su estructura de datos.**  
La rama debe tener un nombre significativo, por ejemplo: `doubly-list`, `stack`... y por supuesto, debe partir del último *commit* de `develop`.

**Usando el fichero *recursos.txt*, completad todas las funciones según vuestro reparto.**  
- Realizad un *commit* tras cada función añadida.
- Subid vuestro progreso tras completar cada tarea del *Project*.
- Cuando completéis un *Milestone*, cread un *Pull Request* para la rama `develop`.

Lo que hacéis con ese último paso es informar a vuestros compañeros de que habéis terminado la funcionalidad en la que trabajábais, de modo que puede ser revisada y aceptada por un superior (en este caso, vosotros mismos).
- El *Pull Request* tendrá como revisores a los otros miembros del equipo.
- Si el código es correcto: los revisores lo aceptarán y se fusionarán los cambios.
- Incluid un comentario en el *Pull Request* para compartir alguna idea (por ejemplo, un "Buen trabajo".).

**Completando todos los *Milestones*, habréis terminado el proyecto. ¡Enhorabuena!**  
Ahora, la parte interesante, uando hayáis terminado el proyecto:
- Cread un *Pull Request* para fusionar **vuestro `develop`** con **mi `develop`**, (repositorio original).
- El *Pull Request* debe describir de forma resumida lo que queréis integrar.

Habéis estado trabajando todo el tiempo entre vosotros y en vuestro repositorio; pero con esto, estaréis trabajando con el repositorio de otro usuario y solicitando integrar vuestros cambios en un repositorio donde no tenéis permisos.

Si el cambio es aceptado (por mí), en el repositorio original apareceréis como contribuyentes y además, ¡habréis terminado el taller!


## Parte Bonus

- Implementad una estructura de datos extra: **los Conjuntos (Set)**.

> Efectivamente, estaban en el fichero de cabeceras **desde el principio**, ¡vaya *plot-twist*!

# Evaluación

He estado hablando con HAL y me ha dicho que no hay forma de evaluar el proyecto, así que no hay evaluación.

*Sí obstante*, si queréis vacilar sobre *quién tiene la rama más larga*, siempre podréis pedírselo a otros de vuestros compañeros, ¡nadie os lo va a impedir!

---

- Proyecto creado por [**@15Galan**](https://srgalan.vercel.app).
