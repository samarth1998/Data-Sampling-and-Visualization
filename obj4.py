import numpy as np
#Ask the user to type the filenames
dataFile = raw_input('File to be analyzed: ') + '.txt'
resultFile = raw_input('File to store analyze result: ') + '.txt'
#Setup the files to read from and to write to
fData = open(dataFile, 'r')
fResult = open(resultFile, 'w')
#Create numpy array to store time
time = np.empty(5000)
missingData = False
#Get rid of the first two lines in data file
fData.readline()
fData.readline()
for i in range(0,5000):
    numbers = fData.readline().split()
    if (str(i + 1) != numbers[0]):
        #If any data missing, set this variable to true
        missingData = True
    time[i] = numbers[4]
fData.close()
time = np.delete(time,0)
fResult.write('Data analysis for file ' + dataFile + '\n')
fResult.write('Missing Samples: ' + str(missingData) + '\n')
fResult.write('Mean time Difference: ' + str(np.mean(time)) + '\n')
fResult.write('Standard Deviation: ' + str(np.std(time)) + '\n')
fResult.write('Maximum time difference: ' + str(np.max(time)) + '\n')
fResult.write('Minimum time difference: ' + str(np.min(time)) + '\n')

time = np.delete(time,range(0,1000))
fResult.write('\n----------------------------\nRemoved data from first 10 seconds\n')
fResult.write('Mean time Difference: ' + str(np.mean(time)) + '\n')
fResult.write('Standard Deviation: ' + str(np.std(time)) + '\n')
fResult.write('Maximum time difference: ' + str(np.max(time)) + '\n')
fResult.write('Minimum time difference: ' + str(np.min(time)) + '\n')
fResult.close()