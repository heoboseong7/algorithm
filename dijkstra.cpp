//20172634 leeminhee

/**
 * Algorithm homework #3
 *
 * "Dijkstra algorithm"
 * - on an undirected weighted graph with 200 vertices labeled 1 to 200
 * - run Dijkstra's shortest-path algorithm on this graph, using 1 (the first
 *   vertex) as the source vertex, and to compute the shortest-path distances
 *   between 1 and every other vertex of the graph. If there is no path between
 *   a * vertex v and vertex 1, we'll define the shortest-path distance between
 *   1 and v to be 1000000.
 *
 * @ Mar. 7 2015
 * @ Jeongyeup Paek
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#ifdef _WIN64   // define something for Windows (64-bit)
    #include <time.h>
#elif _WIN32    // define something for Windows (32-bit)
    #include <time.h>
#elif __APPLE__ // apple
    #include <sys/time.h>
#elif __linux   // linux
    #include <time.h>
#elif __unix    // Unix
    #include <time.h>
#elif __posix   // POSIX
    #include <time.h>
#endif

#define MAX_DISTANCE    1000000     // if no path exists
#define MAX_NUM_NODES   200         // 200 vertices labeled 1 to 200
#define MAX_VERTEX_ID   200         // 200 vertices labeled 1 to 200
#define MAX_NUM_EDGE   2000

struct edge {
   int to;
   int weight;
};

struct vertex {
  int id;             // node id
  unsigned int distance;           // minimum distance to source
  int from;
  bool done;
  struct edge *e[MAX_NUM_NODES-1];
  int num_e;
};
struct vertex *m_varray[MAX_NUM_NODES]; // array of all vertices


/*********************************
 * PUT MORE VARIABLES HERE
 *********************************/

//TODO : 위에 어떤 변수들을 추가하라는 건지 모르겠어..

int m_n = 0;
int m_e = 0;    // total number of i->j edges.
                // 'm_e/2' is the actual number of undirected edges

struct vertex* find_vertex (unsigned int id) {
    struct vertex *v;
    if (id > MAX_VERTEX_ID) {
        printf("%s: error, invalid vertex id %d\n", __func__, id);
        return NULL;
    }

   v = m_varray[id];
   if (v != NULL) {
      return v;
   }
   else {
      return NULL;
   }
}

// find vertex and add if does not exist
struct vertex* add_vertex (unsigned int id) {
    struct vertex *v;

    if (id > MAX_VERTEX_ID) {
        printf("%s: error, invalid vertex id %d\n", __func__, id);
        return NULL;
    }

    if ((v = find_vertex(id)) != NULL) {
        return v;
    }

   v = (struct vertex*)malloc(sizeof(struct vertex));
   v->id = id;
   v->distance = MAX_DISTANCE;
   v->num_e = 0;

   // TODO: 여기서 v->e 들을 다 NULL로 초기화 시켜주면 작동하긴하는데.. 이게 올바른풀이일까..?

    return v;    // TODO
}

// delete all malloc'ed memory (edges and vertices)
void delete_graph() {

   for (int i = 0; i < MAX_NUM_NODES; i++)    // 요소 개수만큼 반복
   {
      for (int j = 0; j < m_varray[i]->num_e; j++) {
         free(m_varray[i]->e[j]);
      }
      free(m_varray[i]);    // 각 요소의 동적 메모리 해제
   }
}

// print shortest distnace of all nodes
void print_all_shortest_distance () {
    int i;
    for (i = 0; i < MAX_NUM_NODES; i++) {

      printf("vertex   %3d : shortest distance   %d\n", i, m_varray[i]->distance);

    }
}

// print shortest path of all nodes
void print_all_shortest_path () {

    /*********************************
     * PUT YOUR CODE HERE
     *********************************/

}

struct edge* find_edge (unsigned int fromid, unsigned int toid) {
   struct vertex* v = find_vertex(fromid);
   struct edge *e;

   if (v == NULL) {
      return NULL;
   }
   else {
      e = v->e[toid];
      if (e != NULL) {
         return e;
      }
      else {
         return NULL;
      }
   }
}

// find edge and add if does not exist
struct edge* add_edge (unsigned int fromid, unsigned int toid,
                       unsigned int ecost) {
    struct vertex *v, *u;
   // TODO: 교수님이 위와 같은 변수들을 만들어 놓았는데 어디다 쓰라는건지 전혀 모르겠는부분..?
   struct edge *e;

    if (fromid > MAX_VERTEX_ID || toid > MAX_VERTEX_ID) {
        printf("%s: error, invalid vertex id %d->%d\n", __func__, fromid, toid);
        return NULL;
    }

   if ((e = find_edge(fromid, toid)) != NULL) {
      return e;
   }

   e = (struct edge*)malloc(sizeof(struct edge));
   e->to = toid;
   e->weight = ecost;

    return e;    // TODO
}


// run Dijkstra algorithm
void run_dijkstra() {

/*********************************
 * PUT YOUR CODE HERE
 *********************************/

}


int read_input_file(char *filename) {
    FILE *fp;
    char linebuf[1000];

    // clear global data before reading the file
    m_n = 0;

    // adjacency list representation of a simple undirected graph
    if ((fp = fopen(filename, "r")) == NULL) {
        perror("Error opening input file\n");
        return -1;
    }

    // read data file, line by line
    while (fgets(linebuf, sizeof(linebuf), fp) != NULL) {

        if (m_n > MAX_NUM_NODES) {
            printf("too many data (n = %d)\n", m_n);
            break;
        }

      char *ptr = strtok(linebuf, "\t");
      m_varray[m_n] = add_vertex(atoi(ptr));
      ptr = strtok(NULL, ",");

      int cnt = 0;

      //14,234
      while (ptr != NULL && strcmp(ptr,"\n")!=0) {

         int to= atoi(ptr);
         ptr = strtok(NULL, "\t");
         int weight = atoi(ptr);

         m_varray[m_n]->e[m_varray[m_n]->num_e++] = add_edge(m_n, to, weight);
         m_e++;
         ptr = strtok(NULL, ",");
      }
      m_n++;
    }
    fclose(fp);

    printf("%s: total: %d nodes, %d edges\n", __func__, m_n, m_e/2);

    return 0;
}


int main (int argc, char *argv[]) {
    char *filename = NULL;

   filename = argv[1];
    read_input_file(filename);

    /* run dijkstra here */
    run_dijkstra();

    /* print shortest distance of all nodes in increasing order of ID */
    print_all_shortest_distance();

    /* if possible, print shortest path of all nodes
    if (option) {
        print_all_shortest_path();
    }*/

    printf("homework output:\n");
    printf("shortest distance to vertices 7,37,59,82,99,115,133,165,188,197\n");
    printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
            m_varray[6]->distance, m_varray[36]->distance,
            m_varray[58]->distance, m_varray[81]->distance,
            m_varray[98]->distance, m_varray[114]->distance,
            m_varray[132]->distance, m_varray[164]->distance,
            m_varray[187]->distance, m_varray[196]->distance);

    /* memory clean up */
    delete_graph();

    /* calculate running time */

/*********************************
 * PUT YOUR CODE HERE
 *********************************/

    //printf("running time = %lu.%03lu seconds\n", sec, msec);  // TODO

    return 0;
}
