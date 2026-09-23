pipeline {
    agent any

    stages {
        stage("build") {
            when {
                expression {
                    BRANCH_NAME == 'dev'
                }
            }

            step {
                echo 'Building the application'
            }
        }

        stage("test") {
            step {
                echo 'Testing the application'
            }
        }

        stage("deploy") {
            step {
                echo 'Deploying the application'
            }
        }
    }

    post {
        success {
            echo 'App is built, tested abd deployed successfully'
        }

        failure {
            echo 'App failed to be built, tested or deployed'
        }
    }
} 