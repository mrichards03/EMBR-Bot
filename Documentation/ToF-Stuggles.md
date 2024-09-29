# ToF Struggles
## The Wrath of Analog Devices

I'm writing this while ill, and have been so for a week. Please read it carefully in order to catch any errors I've made.

## Terminology
1. **ADTF3175** Analog Devices ToF camera.
2. **ADI ToF SDK** library that provides an API to control ToF camera and get data from it.
3. **Crosby** It *seems* to be the codeword for ADTF3175. 
   
## Issues
1. The build instructions didn't include the examples. I had to read a bunch of documentation to figure out why this is happening. This has been fixed to include the examples in build instructions, now the ToF GUI thing builds consistently. 
2. In the same vein, I've managed to make it include ros2 as well. However, please read the following

![Their actual documentation](<documentation-images/SDK Documentation.png>)

You will notice that the initialize function does not have any arguments.

Now, let us see what the build does:
![Their actual code](<documentation-images/Their actual code.png>)
They require a string input.

Now, I tried fixing this bug for them since I'm so nice.

And sure enough - NO

IT STILL ERRORS BUT DOESN'T SAY WHY

