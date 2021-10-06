def trappedWater(height):
  area = 0
  left = 0
  right = left+1
  maxr = len(height)-1
  total = 0

  while left < maxr:
    if height[left] == 0:
      left +=1
      right = left+1
    else:
      area = right-left-1
      if height[right] < height[left]:
        if right == maxr:
          height[left] = height[left] -1
          right = left + 1
          continue
        right += 1
      else:
        total += area
        height[left] = height[left] -1
        right = left + 1
  return total
