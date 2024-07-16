from os import listdir
from os.path import isfile, join
import leetcode
import time

solutionFileDir = "../problems"
# absolutePath = "/hekoh99/daily_leetcode/blob/main/problems"
absolutePath = "/problems"

leetcode_api_instance = leetcode.DefaultApi(leetcode.ApiClient(leetcode.Configuration()))
leetcode_query_get_question_info = """
    query getQuestionDetail($titleSlug: String!) {
        question(titleSlug: $titleSlug) {
            title
            difficulty
            stats
        }
    }
"""


projectTitle = "# Daily Leetcode"
projectDesc = "Daily algorithm practice"

subTitle = "## Progress"

tableHeaderTotal = """\
Total |
------------- |\
"""
tableHeaderDifficulty = """\
$\\bf{\large{\color{#5ad7b7}Easy}}$| $\\bf{\large{\color{#6580DD}Medium}}$ | $\\bf{\large{\color{#DD6565}Hard}}$
------------- | ------------- | -------------\
"""
tableHeaderProblem = """\
\# | Solution Code | LeetCode Link | Difficulty | Accepted Rate
------------- | ------------- | ------------- | ------------- | -------------\
"""

class Problem:
    def __init__(self, problemIndex, problemTitle, solutionFile):
        self.problemIndex = problemIndex
        self.problemTitle = problemTitle
        self.solutionFile = solutionFile
        self.getDetailFromLeetCode()

    def getDetailFromLeetCode(self):
        loopFlag = True
        triedCount = 0
        while loopFlag and triedCount < 10:
            try:
                triedCount += 1
                print("trying to get problem info (try " + str(triedCount) + "): " + self.problemTitle)
                graphqlRequest = leetcode.GraphqlQuery(
                    query=leetcode_query_get_question_info,
                    variables=leetcode.GraphqlQueryGetQuestionDetailVariables(title_slug=self.problemTitle),
                    operation_name="getQuestionDetail"
                )

                info = leetcode_api_instance.graphql_post(body=graphqlRequest)
                question = info.data.question
                self.title = question.title
                self.difficulty = question.difficulty
                self.acRate = eval(question.stats)['acRate']
                loopFlag = False
            except Exception as e:
                if (triedCount >= 30): raise e
                print("*** Exception occured: " + str(e))
                time.sleep(0.3)

    def getLeetCodeLinkTitle(self):
        return self.problemIndex + ". " + self.title
        
    def getLeetCodeLink(self):
        return "https://leetcode.com/problems/" + self.problemTitle
        
    def getSolutionPath(self):
        return absolutePath + "/" + self.solutionFile + "/" + self.solutionFile + ".cpp"
    
    def getDifficultyColor(self, difficulty):
        difficultyColor = {"Easy" : "#5ad7b7", "Medium": "#6580DD", "Hard" : "#DD6565"}.get(difficulty, "#FFFFFF")
        return "$\\bf{\large{\color{" + difficultyColor + "}"+ difficulty +"}}$"
        
    def convertIntoReadMe(self):
        return self.problemIndex +\
            " | " + "["+self.title+"]("+self.getSolutionPath()+")" +\
            " | " + "["+self.getLeetCodeLinkTitle()+"]("+self.getLeetCodeLink()+")" +\
            " | " + self.getDifficultyColor(self.difficulty) +\
            " | " + self.acRate +\
            "\n"

def getTotalInfo(problems):
    return str(len(problems)) + " |"

def getDifficultyInfo(problems):
    easy_count = sum(problem.difficulty == 'Easy' for problem in problems)
    medium_count = sum(problem.difficulty == 'Medium' for problem in problems)
    hard_count = sum(problem.difficulty == 'Hard' for problem in problems)
    return str(easy_count) + " | " + str(medium_count) + " | " + str(hard_count)

def getProblemInfo(problems):
    content = ""
    for problem in problems:
        content += problem.convertIntoReadMe()
    return content

solutionFiles = [f for f in listdir(solutionFileDir) if f[:4].isdigit()]
problems = []
for solutionFile in solutionFiles:
    split = solutionFile.split(".")[0].split("-")
    # 문제 번호, 문제 이름, 파일명 분리
    problemIndex = split[0]
    problemTitle = "-".join(split[1:])
    problem = Problem(problemIndex, problemTitle, solutionFile)
    # 리스트에 삽입
    problems.append(problem)

readme = open("../README.md", "w")
readme.write(projectTitle + "\n" + projectDesc + "\n\n")
readme.write(subTitle + "\n")
readme.write(tableHeaderTotal + "\n" + getTotalInfo(problems) + "\n\n")
readme.write(tableHeaderDifficulty + "\n" + getDifficultyInfo(problems) + "\n\n")
readme.write(tableHeaderProblem + "\n" + getProblemInfo(problems))

readme.close()
    