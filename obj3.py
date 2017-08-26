import serial
#Setup parameters for sensors
gyroRange = 250
accRange = 2
aser = serial.Serial('COM6', 115200)  #Setup Arduino serial with 115200 baud

#Function to scale raw data for different sensor types
def scale(data):
    if sensorType == '1':
        return float(data) / 1023 * 3.3
    elif sensorType == '2':
        return (float(data)/32768.9)*gyroRange
    elif sensorType == '3':
        return (float(data)/32768.0)*accRange

#Function to get one tab/new line separated number from serial
def getNumber():
    local = ''
    while (local == ''):
        data = aser.read()
        while (data >= '0' and data <= '9'):
            local += data;
            data = aser.read()
    return local

#Prompt user to input filename and sensor type
filename = raw_input('File name to save data to:\n') + '.txt'
sensorType = raw_input('Type 1 to sample from the analog input, type 2, Gyro, 3, Accelerometer:\n')
#Open a file object to write data to
f = open(filename, 'w')
#Write the sensor type to serial to start the Arduino sampling
aser.write(sensorType)
#Get rid of the first line in serial that indicates user to input
aser.readline()
#Write description to the beginning of the file
if sensorType == '1':
    f.write('Analog Input Data\nSampleNo.\tA0(V)\t\tA1(V)\t\tA2(V)\tElapsed Time(milliseconds)\n')
elif sensorType == '2':
    f.write('Gyro Data\nSampleNo.\tX(°/s)\t\tY(°/s)\t\tZ(°/s)\tElapsed Time(milliseconds)\n')
elif sensorType == '3':
    f.write('Acc Data\nSampleNo.\tX(g)\t\tY(g)\t\tZ(g)\tElapsed Time(milliseconds)\n')

#Setup a variable to count amount of samples
count = 0
while(count < 5000):
    #Get sample No. from the first number of the line
    count = int(getNumber())
    print 'Sampling in progress ...  ' + str(count / 50) + '%'
    #Form the line writting to the data file
    line = str(count) + '\t' + str(scale(getNumber())) + '\t' + str(scale(getNumber())) + '\t' + str(scale(getNumber())) + '\t' + str(float(getNumber()) / 1000) + '\n'
    #Write the line to the file    
    f.write(line)
#Close serial
aser.close()
#Close file after 5000 samples
f.close()
