Exercicios discursivos:

1- O que é a GLSL? Quais os dois tipos de shaders são obrigatórios no pipeline programável
da versão atual que trabalhamos em aula e o que eles processam? 
R: É uma linguagem de programação, chamada OpenGL Shaer Language, parecida com C, porém voltada a implementação de shaders. Vertex Shaders, processam um vértice; Fragment Shaders, processam uma área.

2- O que são primitivas gráficas? Como fazemos o armazenamento dos vértices na OpenGL?
R: São conjuntos de pontos que vão compor os elementos de um cenário. Armazenamos os vertices normalmente em matrizes de floats.

3- Explique o que é VBO, VAO e EBO, e como se relacionam (se achar mais fácil, pode fazer
um gráfico representando a relação entre eles). 
R: VBO é uma estrutura de dados provida pelo OpenGL que permite armazenar individualmente na placa gráfica os dados de vértices.
VAO é a coleção de todos os dados de vértices.
EBO é uma estrutura que armazena indices dos vértices para permitir um fácil acesso ao vertice que vai ser desenhado.

4- 
No artigo VBO é utlizado  para armazenar os vertices do triangulo na memória da placa de vídeo, com o seguinte bloco de código:
```c++

GLuint vbo = 0;
glGenBuffers(1, &vbo);
glBindBuffer(GL_ARRAY_BUFFER, vbo);
glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

```
No artigo VAO é utilizada para armazenar os vertices que serão utilizados, com o seguinte código:
```c++

GLuint vao = 0;
glGenVertexArrays(1, &vao);
glBindVertexArray(vao);
glEnableVertexAttribArray(0);
glBindBuffer(GL_ARRAY_BUFFER, vbo);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

```

No artigo Shaders são utilizados para definir como os vértices vão ser desenhados, compostos por vertex shaders, que controlam os pontos 3d's e fragment shaders que vão contolar as cores e as superfícies.
O código abaixo foi utilizado no artigo a partir da GLSL, uma linguagem da OpenGL para implementar shaders:
```glsl
const char* fragment_shader =
"#version 400\n"
"out vec4 frag_colour;"
"void main() {"
"  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
"}";

```
E para compilar o shader:
```c++
GLuint vs = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vs, 1, &vertex_shader, NULL);
glCompileShader(vs);
GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fs, 1, &fragment_shader, NULL);
glCompileShader(fs);
```
E finalmente para utilizar o shader:
```c++
GLuint shader_programme = glCreateProgram();
glAttachShader(shader_programme, fs);
glAttachShader(shader_programme, vs);
glLinkProgram(shader_programme);
```
