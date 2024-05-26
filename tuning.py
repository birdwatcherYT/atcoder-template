import argparse
import joblib
import optuna
import subprocess
import numpy as np

# 並列数
N_JOBS = 4
# スコアの平均を取るテストケースの数
N_FILES = 100
# 試行回数
N_TRIALS = 1000
# 保存名
STORAGE = "sqlite:///ahc.db"
STUDY_NAME = "tune_param"
# プログラム名
PROGRAM = "tuning_sample.exe" # for windowns
# PROGRAM = "./tuning_sample.exe" # for mac/linux


def run(seed: int, param1: float, param2: float):
    result = subprocess.getoutput(f"{PROGRAM} {seed} {param1} {param2}")
    return float(result.strip().split()[-1])


def objective(trial: optuna.trial.Trial):
    param1 = trial.suggest_float("param1", -100, 100)
    param2 = trial.suggest_float("param2", -100, 100)

    scores = joblib.Parallel(n_jobs=N_JOBS)(
        joblib.delayed(run)(i, param1, param2) for i in range(N_FILES)
    )
    return np.mean(scores)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-v", "--visualize", action="store_true")
    args = parser.parse_args()
    if args.visualize:
        study = optuna.load_study(storage=STORAGE, study_name=STUDY_NAME)
        fig = optuna.visualization.plot_optimization_history(study)
        fig.show()
        fig = optuna.visualization.plot_contour(study)
        fig.show()
    else:
        study = optuna.create_study(
            direction="maximize",
            storage=STORAGE,
            study_name=STUDY_NAME,
            load_if_exists=True,
        )
        study.optimize(objective, n_trials=N_TRIALS)
