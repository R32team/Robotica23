import pandas as pd
from sklearn.tree import DecisionTreeClassifier
import numpy as np

# create a dataframe to hold the questions and possible answers
questions = pd.DataFrame({
    'Question': [
        'Are you interested in Italian Renaissance art?',
        'Do you prefer paintings or sculptures?',
        'Are you interested in religious art?',
        'Would you like to see works by Leonardo da Vinci or Michelangelo?',
        'How much time do you have to spend at the museum?'
    ],
    'Answers': [
        ['Yes', 'No'],
        ['Paintings', 'Sculptures', 'Both'],
        ['Yes', 'No'],
        ['Leonardo da Vinci', 'Michelangelo', 'Both', 'Neither'],
        ['1 hour', '2-3 hours', '4-5 hours', 'More than 5 hours']
    ]
})

# create a function to ask the questions and collect the answers
def collect_answers():
    answers = []
    for i in range(len(questions)):
        print(questions['Question'][i])
        for j in range(len(questions['Answers'][i])):
            print(f'{j + 1}. {questions["Answers"][i][j]}')
        answer = input('> ')
        while answer not in [str(x + 1) for x in range(len(questions['Answers'][i]))]:
            print('Invalid input, please try again.')
            answer = input('> ')
        answers.append(int(answer) - 1)
    return answers

# load the data for the museum exhibits
data = pd.read_csv('data.csv')

# train a decision tree classifier on the data
X = data.drop(columns=['Title', 'Author', 'Room'])
y = data['Title']

clf = DecisionTreeClassifier()
clf.fit(X, y)

# collect the visitor's answers to the questions
print('Please answer the following questions:')
answers = collect_answers()

# predict the exhibit route based on the answers
ans   = np.array(answers)
ans   = ans.reshape(-1,1)
route = clf.predict(ans)
route = list(route)
visited = set()
route[:] = [x for x in route if x not in visited and not visited.add(x)]

print(f'Your personalized route is:')
for idx in route:
    print(idx)
