
def sort(input_array, low, high):
  if low < high:
    pi = partition(input_array, low, high)

    sort(input_array, low, pi -1)

    sort(input_array, pi + 1, high)


def partition(input_array, low, high):
  pivot = input_array[high]
  counter = low - 1
  for i in range(low, high):
    if input_array[i] <= pivot:
      counter += 1
      temp = input_array[counter]
      input_array[counter] = input_array[i]
      input_array[i] = temp
  temp = input_array[counter+1]
  input_array[counter+1] = input_array[high]
  input_array[high] = temp
  return counter + 1