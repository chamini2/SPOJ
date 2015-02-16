module Main where
import Control.Monad (unless, liftM)

main = liftM read getLine >>= \a -> unless (a == 42) $ print a >> main