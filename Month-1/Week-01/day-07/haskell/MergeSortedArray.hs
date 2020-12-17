module MergeSortedArray
  ( mergeSortedArray
  ) where

import           Control.Monad
import           Data.Array.IO

mergeSortedArray :: IOArray Int Int -> IOArray Int Int -> IO ()
mergeSortedArray nums1 nums2 = do
  dst  <- slice nums1
  src2 <- slice nums2
  let src1  = dropS (lengthS src2) dst
  let src1' = takeS (lengthS src1) dst
  copy src1' src1
  merge src1 src2 dst

type Slice = (IOArray Int Int, Int, Int)

slice :: IOArray Int Int -> IO Slice
slice a = do
  bounds@(base, _) <- getBounds a
  return (a, base, rangeSize bounds)

lengthS :: Slice -> Int
lengthS (_, _, m) = m

nullS :: Slice -> Bool
nullS = (== 0) . lengthS

headS, lastS :: Slice -> IO Int
headS (a, i, _) = readArray a i
lastS (a, i, m) = readArray a (i + pred m)

initS, tailS :: Slice -> Slice
initS (a, i, m) = (a, i, pred m)
tailS (a, i, m) = (a, succ i, pred m)

takeS, dropS :: Int -> Slice -> Slice
takeS m (a, i, _) = (a, i, m)
dropS n (a, i, m) = (a, i + n, m - n)

put, put' :: Slice -> Int -> IO ()
put (a, i, _) = writeArray a i
put' (a, i, m) = writeArray a (i + pred m)

copy :: Slice -> Slice -> IO ()
copy src dst
  | nullS src = return ()
  | otherwise = lastS src >>= put' dst >> copy (initS src) (initS dst)

merge :: Slice -> Slice -> Slice -> IO ()
merge src1 src2 dst
  | nullS src1 && nullS src2 = return ()
  | nullS src1 = headS src2 >>= put dst >> merge src1 (tailS src2) (tailS dst)
  | nullS src2 = headS src1 >>= put dst >> merge (tailS src1) src2 (tailS dst)
  | otherwise = do
    e1 <- headS src1
    e2 <- headS src2
    if e1 < e2
      then put dst e1 >> merge (tailS src1) src2 (tailS dst)
      else put dst e2 >> merge src1 (tailS src2) (tailS dst)
