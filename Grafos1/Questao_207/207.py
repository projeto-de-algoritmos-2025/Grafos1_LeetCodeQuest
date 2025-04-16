from collections import defaultdict
class Solution:
    def canFinish(self, numCourses, prerequisites):
        self.grafo = defaultdict(list)  # Cria um grafo para armazenar as dependências entre ps cursos
        for course, prereq in prerequisites:
            self.grafo[course].append(prereq) 
        self.visitados = set()    # Conjunto para controlar cursos visitados 
        self.verificados = set()  # Conjunto para controlar cursos verificados
        self.numCourses = numCourses  # Armazena o número total de cursos
        return self.Pode_concluir_todos()
    def Pode_concluir_todos(self): # Verifica se é possível concluir todos os cursos
        for curso in range(self.numCourses):
            if not self.dfs(curso):
                return False  # Se encontrar um ciclo, não é possível concluir todos os cursos
        return True  # Todos os cursos podem ser concluídos
    def dfs(self, curso): # Realiza uma busca para verificar se há ciclos em um curso
        if curso in self.verificados:
            return True  # Já verificado, não possui ciclo
        if curso in self.visitados:
            return False  # Ciclo detectado
        self.visitados.add(curso)  # Marca o curso como visitado
        for prereq in self.grafo[curso]: # Percorre os cursos que são pré-requisitos do curso atual
            if not self.dfs(prereq):  # Se qualquer pré-requisito não puder ser concluído, retorna Falso
                return False  
        self.visitados.remove(curso)  
        self.verificados.add(curso)  # Marca o curso como verificado
        return True  # Sem ciclo, curso pode ser concluído
